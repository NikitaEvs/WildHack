#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <Spix/QtQmlBot.h>

#include <atomic>
#include <gtest/gtest.h>
#include <QtWidgets/QApplication>

#include "Gui.h"
#include "Engine/GameEngine.h"

class GUITest;
static GUITest* srv;

class GUITest : public spix::TestServer {
 public:
  GUITest(int argc, char* argv[]) {
    m_argc = argc;
    m_argv = argv;
  }

  int testResult() { return m_result.load(); }

 protected:
  int m_argc;
  char** m_argv;
  std::atomic<int> m_result {0};

  void executeTest() override {
    srv = this;
    ::testing::InitGoogleTest(&m_argc, m_argv);
    auto testResult = RUN_ALL_TESTS();
    m_result.store(testResult);
  }
};

TEST(GTestExample, BasicUITest)
{
  srv -> mouseClick(spix::ItemPath("applicationWindow/enterView/enter"));
  srv -> wait(std::chrono::milliseconds(500));
  auto result = srv -> getStringProperty("applicationWindow/canvasLoad", "text");
  ASSERT_EQ(result, "true");

  srv->quit();
}

int main(int argc, char* argv[])
{
  QGuiApplication app(argc, argv);
  QQmlApplicationEngine engine;

  std::shared_ptr<GameEngine> gameEngine = std::make_shared<GameEngine>();
  std::shared_ptr<Gui> gui = std::make_shared<Gui>(gameEngine);

  engine.rootContext() -> setContextProperty("gui", gui.get());
  engine.load(QUrl(QStringLiteral("../../resources/layout/main.qml")));
  if (engine.rootObjects().isEmpty())
    return -1;

  GUITest tests(argc, argv);
  auto bot = new spix::QtQmlBot();
  bot->runTestServer(tests);

  app.exec();
  return tests.testResult();
}