# WildHack

[![Actions Status](https://github.com/NikitaEvs/peach/workflows/unit_tests/badge.svg)](https://github.com/NikitaEvs/peach/actions)
[![Actions Status](https://github.com/NikitaEvs/peach/workflows/gui_test/badge.svg)](https://github.com/NikitaEvs/peach/actions)

_Игра про животных и не только_

![Start view](.github/pictures/punk.png)

![Cells map](.github/pictures/cells.png)

![GamePlay](.github/pictures/game.png)

![Mutations](.github/pictures/mutation.png)

Игровая механика описана [здесь](docs/gameplay.md)

Запуск [примера](test/test.cpp) с генерацией клеток, популяций и карты

```shell script
mkdir build
cd build
cmake ..
make
cd bin
./example
```

К тому же, возможна сборка Unit тестов, GUI приложения, а также GUI тестов, но это требует множества
зависимостей (скрипты по установке можно найти [здесь](ci)). 

Сборка и запуск Unit тестов (требуются зависимости, которые устанавливаются скриптом [unitTest.sh](ci/unitTest.sh))

```shell script
mkdir build
cd build
cmake -DTEST_BUILD=ON ..
make
cd bin
./gtest
```

Сборка и запуск GUI (требуются зависимости, которые устанавливаются скриптом [gui.sh](ci/gui.sh))

Теперь можно поиграть!

```shell script
mkdir build
cd build
cmake -DGUI_BUILD=ON ..
make
cd bin
./gui --style material
```

При желании можно настроить игровой мир в конфигурационном [файле](resources/config/values.json)

Сборка и запуск GUI тестов (требуются зависимости, которые устанавливаются скриптом [guiTest.sh](ci/guiTest.sh))

```shell script
mkdir build
cd build
cmake -DGUI_BUILD=ON -DGUI_TEST_BUILD=ON ..
make
cd bin
./guiTest
```

---
Описание используемых паттернов можно найти [здесь](docs/patterns.md)

Документацию можно найти [здесь](https://nikitaevs.github.io/peach)