# Итоговое зачетное задание

1. Разработать класс-шаблон, поддерживающий модель «Матрица» произвольных размеров (не только квадратных), 
позволяющий создавать объекты на базе всех числовых системных типов данных. 
В классе необходимо предусмотреть следующие свойства и методы (не запрещено добавлять дополнительные, при необходимости реализации вашей творческой идеи):

  - [x] Конструктор с параметрами, задающими размерность (или размерности, в случае с неквадратной матрицей), число заполнитель матрицы. 
Все операции по выделению памяти для динамических двумерных массивов, должны выполняться с проверками на правильность и допустимость выполнения операций! 
  > **Отсутствие таковых в этом и дальнейших пунктах – приводит к снижению оценки за задание в целом!**

  - [x] Деструктор, проверяющий существование указателя на динамический массив, и производящий безопасное освобождение памяти.

  - [x] Перегруженные операторы индексации, сравнения матриц (равенство означает полное совпадение всех параметров и значений поэлементно, 
но не указателя на область памяти!), сложения, умножения матриц (с соответствующими проверками!!!), а также присваивания (выполняется поэлементно)

  - [ ] Методы поиска максимального и минимального элементов в матрице, с возвращением указателя на найденный элемент (если их несколько, то на первый обнаруженный)

  - [x] Методы вычисления ранга матрицы, ее определителя (если матрица квадратная, в противном случае возвращать число -999333)

  - [x] Метод Транспонирования (метод должен либо транспонировать исходную матрицу объекта, либо возвращать временный объект, чтобы его можно было присвоить другому объекту, с помощью оператора присваивания – который перегружен) с параметром, определяющим, менять исходную матрицу или возвратить временный объект для присваивания другому объекту.

  - [x] Метод вычисления обратной матрицы.

  - [ ] Метод, приводящий матрицу верхнему диагональному виду (с учетом и проверкой возможности такого приведения, используя ранг матрицы!)

2. Создать класс, реализующий модель системы линейных уравнений (далее – СЛУ), в матричном виде. 
Класс может быть унаследован от класса из 2.1, либо содержать необходимые объекты внутри себя – в любом случае, 
обязательно обосновать выбор применения того или иного подхода. Класс должен обеспечивать:

  - [ ] Задание размерностей СЛУ (число неизвестных, и число самих уравнений) – с проверкой допустимости значений.
  - [ ] Заполнение всех матриц коэффициентов и вектора правой части системы.
  - [ ] С помощью методов матричных операций из 2.1 – выполнять поиск решения СЛУ (методом Гаусса), опять же, используя матричные методы из 2.1.
  - [ ] В Случае (используйте метод вычисления рангов матриц!) несовместности СЛУ, предупредить пользователя об отсутствии решений.

> Особое внимание при проверке будет уделяться контролю безопасности работы с данными, проверке значений и 
отсутствие двусмысленности при работе методов, исключений различных ситуаций при которых система придет в нефункциональное состояние. 

**Проект должен быть выполнен из двух частей:**

1. Проект, с самим программным кодом (комментарии элементов кода и алгоритмов обязательны) для возможности проверки отладки и демонстрации работы
2. Документация, с описанием выбранных типов данных, классов, реализации ключевых методов (указанных в задании) и алгоритмов, описание типовых операций, и т.д.  
Документация оформляется как иллюстрированный документ *.docx. Обязательно указание автора проекта, и уникальных особенностей программы. 

**При разработке проекта можно пользоваться наработками, которые уже были проверены и отлажены на лабораторных занятиях.**

Желаю удачи!!!)
