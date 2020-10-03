# Используемые паттеры

---
# Порождающие
## Строитель
### Проблема
Необходимо уметь создавать клетки, параметры которых определяются пошагово. Для правильной генерации
нужно учитывать большое количество параметров вероятности. Необходимо уметь генерировать не только
сам класс клеток, но и его сериализацию для сохранения карты.
### Решение
Использование паттерна *Строитель*, что позволяет вынести конструирование объекта за пределы класса.
### Реализация
[Абстрактный строитель](../src/Map/AbstractCellTypeBuilder.h)

[Строитель для класса](../src/Map/CellTypeBuilder.h)

[Строитель сериализации](../src/Map/CellTypeJSONRepresentationBuilder.h)

[Директор](../src/Map/CellTypeDirector.h)
### Проблема
Популяции - объекты, которыми управляет игрок - могут быть травоядными и плотоядными, а так же иметь разные размеры (при инициализации: большой, средний и маленький). Чтобы конструировать животных разных размеров в зависимости от способа питания, нужно при конструировании популяции каждый раз писать много однотипного кода.
### Решение
Применение паттерна "строитель" позволяет вынести конструирование за пределы класса популяции, что улучшает читаемость кода и облегчает конструирование различных типов популяций.
### Реализация
[Абстрактный строитель](../src/Animals/PopulationBuilder.h)

[Строитель травоядной популяции](../src/Animals/HerbivorePopulationBuilder.cpp)

[Строитель плоточдной популяции](../src/Animals/CarnivorePopulationBuilder.cpp)

[Директор](../src/Animals/PopulationDirector.h)

## Синглетон
### Проблема
Необходимо предоставить глобальную точку доступа для объектов, иниициализация которых занимает много
времени, а требуются они часто.
### Решение
Использование паттера *Одиночка*, что позволяет получить глобальную точку доступа к сложным объектам.
### Реализация
[Синглетон для класса с конфигурацией](../src/util/Config.h)

[Синглетон для класса с рандомным генератором](../src/util/RandomGenerator.h)

[Синглетон для констант интерфейса](../resources/string/string.qml)

[Синглетон для констант интерфейса](../resources/colors/light.qml)

# Структурные
## Фасад
### Проблема
Необходимо по запросу от пользователя проводить большое количество действий с внутренними классами
для поддержки игровой механики.
### Решение
Использование паттерна *Фасад* для обеспечения простого интерфейса взаимодействия с визуализацией.
### Реализация
[Движок для игровой механики](../src/Engine/GameEngine.h)

## Адаптер
### Проблема
Необходимо обеспечивать взаимодействие объектов с разными интерфейсами. Например, GUI и игрового движка.
### Решение
Использование паттерна *Адаптер* для взаимодействия между разными объектами.
### Реализация
[Взаимодействие GUI и движка](../gui/Interface/Gui.h)

[Взаимодействие тестовой системы для GUI и google test](../gui/Test/guiTest.cpp)

## Декоратор
### Проблема
Нужна возможность вызова функции адаптера из интерфейса, для этого ей необходимо придать требуемый стандартом вид.
### Решение
Использование паттерна *Декоратор*
### Реализация
[Некоторые функции в адаптере](../gui/Interface/Gui.h)

## Компоновщик
### Проблема
Мутации определяют как в течении игры изменяются параметры популяции. Причем у конкрутной популяции появляется много мутаций, которые могу образовывать дерево. Нужно уметь подсчитывать как совокупность всех мутаций меняет параметры популяции, а так же добавлять новые мутации.
### Решение
Применение паттерна "компоновщик" позволят сконструировать дерево мутаций, в котором могут храниться как сами мутации, так и узлы, в которых эти мутации расходятся и легко вычислять необходимые нам параметры. 
### Реализация
[Абстрактный компонент дерева мутаций](../src/Animals/Mutations/MutationComponent.h)

[Мутация "лист"](../src/Animals/Mutations/LeafMutation.h)

[Контейнер мутаций](../src/Animals/Mutations/CompoundMutation.h)

# Поведенческие
## Цепочка обязанностей
### Проблема
Для реализации бота необходимо задать последовательность действий, которые должны быть выполнены над популяциями, которые у него есть. Но популяций не фиксированное количество и выполняемые с ними действия должны быть разными. Поэтому нам нужна возможность формировать последовательно не фиксированное количестово запросов разного характера.
### Решение
Применение паттерна "Цепочка обязанностей" позволят выполнить различные операции над всеми популяциями бота.
### Реализация
[Абстрактная цепочка](../src/Engine/Handler/Handler.h)

В той же директории разные типы обработчиков

[Применение](../src/Engine/GameEngine.cpp)

## Команда
### Проблема
Необходимо связать интерфейс и движок игры так, чтобы при нажатии пользователем на кнопку в движок передавался запрос.
### Решение
Для передачи запросов как объектов используется паттерн "Команда"
### Реализация
[Абстрактная команда](../gui/Interface/GUICommands/GUICommand.h)

## Наблюдатель
### Проблема
Необходимо иметь функционал оповещения множества интерфейсов об обновлении данных, но заранее количество
интерфейсов неизвестно.
### Решение
Использование паттерна "Наблюдатель" для обеспечения механизма подписки интерфейсов.
### Реализация
[Наблюдатель](../src/Engine/Manager.h)

[Абстрактный подписчик](../src/Engine/Subscriber.h)

[Конкретный подписчик](../gui/Interface/Gui.h)

Также этот паттерн используется в механизмах взаимодействия QML интерфейса с адаптером на C++.