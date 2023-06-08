<div align="center">
  <a href="https://www.youtube.com/watch?v=B42ddIgtTGs"><img src="https://i.ibb.co/3myjWpn/compiler-logo.jpg" alt="compiler-logo" border="0"></a>
</div>

# The Anthon programming language #

## Описание языка ##
 
~~Py~~Anthon - это простейший (как и его создатели) в освоении, мощный (20 000 операций в секунду) язык программирования. Он так же никому не нужен, как и Python, но мы все равно не теряем надежды сдать зачет. Элегантный синтаксис Anthon вместе с его компилируемым характером делают его идеальным языком для написания DFS, сортировки пузырьком и получения автомата. Компилятор Anthon легко дополняется новыми функциями и типами данных, реализованными на C или C++ (или других языках, вызываемых из C).

Этот учебник неформально знакомит читателя с основными понятиями и особенности языка и системы Anthon. Этот учебник не пытается быть всеобъемлющим и охватывать все до единого. Вместо этого он вводит многие из наиболее примечательных особенностей Anthon и дает Вам хорошее представление о стиле языка. Изучив его, Вы сможете прочитать и написать свои первые программы на Anthon (однако в целесообразности сего деяния мы сильно сомневаемся).
 
## Установка компилятора ##

Прежде чем запустить свою первую программу на Anthon, Вам необходимо установить компилятор. Обсудим, как это сделать. 

Скачивайте deb пакет на свою линуксоидную arm64 машину:
```bash
sudo apt install wget
wget https://github.com/Trilonka/cpp_compiler_example/releases/download/V1.0-1/anthonlang_1.0-1_arm64.deb
```

И извлекайте его:
```bash
dpkg -i anthonlang_1.0-1_arm64.deb
```

Теперь можете "наслаждаться" работой нашего компилятора, запуская свой код как в примере ниже:
```bash
anthonlang /path-to-your-das-file/your-das-file-name.das
```
 
## Словарь терминов ##

Данный блок содержит краткую информацию о поддерживаемых языком ключевых словах и символах.

### Встроенные типы данных ###	
`int` - целое отрицательное или положительное число    
`real` - вещественное отрицательное или положительное число    
`bool` - булев тип, в котором хранится либо '0' (ложь), либо '1' (истина)  
`char` - единичный символ   
`string` - последовательность символов  

### Cимволы ###
- круглые скобки `(`, `)`  
- фигурные скобки `{`, `}`  
- квадратные скобки `[`, `]`  
- знаки сравнения `<` (меньше), `>` (больше), `==` (равно), `!=` (не равно)  
- знаки арифметических операций `+` (плюс), `-` (минус), `*` (умножение), `/` (деление)   
- двойные и одинарные кавычки `"`, `'`  
- оператор присваивания `=`  
- логическое отрицание `!`  
- точка с запятой `;`  
- запятая `,`  
- точка `.`  

### Другие ключевые слова ###
`if` - условный оператор 'если'  
`else` - ключевое слово, используемое для выполнения последующего блока действий, если проверяемое в операторе `if` утверждение было ложным   
`for` - оператор, позволяющий повторять последующий блок действий указанное число раз    
`while` - оператор цикла с предусловием  
`print` - фуннкция вывода данных в консоль  
`read` - функция ввода данных через консоль  
`or` - логическое 'или'   
`and` - логическое 'и'   

## Краткое руководство пользователя ##

Изучение этого блока позволит Вам полностью разобраться в синтаксисе языка.

### Встроенные типы данных ###

Каждая переменная имеет определенный тип. Этот тип определяет, какие значения может иметь переменная, какие операции с ней можно производить и сколько байт в памяти она будет занимать. В языке Anthon определены следующие базовые типы данных: `int`, `real`, `bool`, `char`, `string`. Т.к. язык является строго типизированным, объявление типа переменной является обязательным условием. Имя переменной уникально. 

Рассмотрим основные группы по отдельности.

#### Численные типы ####

Численные типы предсатвлены следующими типами:

* целочисленный `int` [от -2 147 483 648 до 2 147 483 647]. 

* тип с плавающей точкой `real` [от +/- 1.7E-308 до 1.7E+308].

```
real r = 21.3;
```

Числа могут принимать как положительные, так и отрицательные значения.

При вычислениях может произойти переполнение, при этом: если значение выходит за нижний диапазон, то, например,
вместо -2 147 483 649 примет значение 2 147 483 647, -2 147 483 650 ->2 147 483 646 и тд. Поэтому будьте осторожны в вычислениях!

При операциях с типом данных real идет округление до 15 знаков после плавающей точки.

#### Логический тип ####

Логический тип `bool` может хранить одно из двух значений: либо '0' (ложь), либо '1' (истина). Например, определим переменную данного типа и выведем ее значение на консоль.

```
bool a = 1;
print(a);
```

Как правило, данный тип применяется преимущество в условных выражениях, которые будут рассмотрены далее.


#### Символьные типы ####

Символьные типы предсатвлены следующими типами:

* `char` может содержать лишь один символ. В качестве значения переменная типа char принимает только символ в одинарных кавычках.

```
char c = 'c';
```

* `string` представляет собой последовательность символов любой длины. Чтобы присвоить перменнйо типа `string` значение, необходимо задать его в двойных кавычках.

```
string s = 'lol kek 56';
```

### Массивы ###

Anthon поддерживает только статические массивы. Для объявления массива необходимо объявить тип данных, из которых он состоит, а так же кол-во элементов в нем. Кол-во элементов объявляется в квадратных скобках.

```
int a[10]; char i[3];
```

Присвоить значения элементам массива возможно непосредствено указав номер элемента. 

```
a[0] = 0; a[1] = 1; 
```

Для ускорения этого процесса советуем воспользоваться оператором `for`.

```
for (int i = 0; i < 2; i = i + 1)
 a[i] = i;
```

Другим способом инициализации массива является перечисление значений элементов в фигурных скобках через запятую. Длину массива при этом указывать не обязательно.
```
int arr[] {1, 2, 3, 4, 5, 6, 7, 8};
```

### Как сообщать и получать данные? ###

Существует несколько способов представления входных и выходных данных программы. 

#### Ввод инфомрации ####

Данные могут быть присвоенны переменной как в самой программе, так и введены через консоль. Для присвоенния переменной значения можно воспользоваться оператором `=`, либо ввести его с клавиатуры, воспользовавшись ключевым словом `read`.

```
int a;
a = 5;
```

Ключевое слово `read` позволяет считывать сразу несколько переменных, введенных через пробел.

```
int a; real b; char c;
read(a, b, c);
```

#### Вывод информации ####

Для вывода данных Вы можете использовать ключевое слово `print`.

```
int a = 10;
print(a);
```
В результате выполнения этой программы в консоли появится число 10.

или ключевое слово `println` для вывода с переносом строки.

```
int a = 10;
int b = 15;
println(a, b);
```
В результате выполнения этой программы в консоли выведутся числа 10 и 15 с переносом строки после каждого.


### Использование ключевых слов ###

Обсудим некоторые встроенные операторы.

#### Оператор `if` ####

Условный оператор `if` - самый простой оператор для принятия решения. Он используется для определения того, будет ли выполняться определенный оператор или блок операторов, т.е. если определенное условие истинно, тогда блок оператора выполняется, иначе - нет.

```
if (условие) { ...; }
```
Рассмотрим конкретные случаи. 
```
int a = 1;

if (a == 0)
  print('no');
```
Переменной `а` было присвоено значение 1. Из-за того что условие оператора `if` не является верным, тело оператора не будет выполненно. 
```
if (a == 1) {
  а = 2;
  println('yes', a);
}
```
В результате выполненния вышепредставленной программы переменной `a` присвоится значение 2, а затем в консоль выведется слово `yes` и новое значение `a`.
#### Оператор `else` ####

`else` используется, чтобы сказать компьютеру, какие инструкции нужно выполнить, если проверяемое утверждение было ложным. Программа сначала проверит первое условие и, если оно ложно, выполняются инструкции внутри `else`, поэтому оно всегда должно стоять в конце.

```
if (условие) { ...; } else { ...; }
```
Например, 
```
int a = 9;
int b = 5;

if (a < b) {
    print("a lower gagaga");
}
else {
    print("b lower hohoho");
};
```
Так как условие в круглых скобках ложно (переменная `а` больше `b`), блок с выводом текста `a lower gagaga` будет пропущен. В результате выполнения программы в консоль выведется текст `b lower hohoho`, что соотвествует коду в фигруных скобках за ключевым словом `else`.

#### Оператор `for` ####

Используйте инструкцию `for` для создания циклов, которые должны выполняться указанное количество раз. Выполняет оператор повторно до тех пор, пока условное значение не станет false. 

```
for ( ; ; ) { ...; }
```
Обсудим, что произойдет в результате исполнения следующей программы:
```
for (int i = 0; i < 3; i = i + 1) { 
  ptintln(i);
}
```
В теле `for` создается переменная `i` со значением 0. Переменная существует только в области видимости блока это оператора. После первой точки с запятой указывается условие. Пока оно истинно, программа внутри блока повтоярется. После второй точки с запятой может быть указан список действий через запятую, которые должны выполняться после каждой иттерации. В результат выполнения программы будут выведены цифры 0, 1 и 2 с новой строки каждая. 

#### Оператор `while` ####

Цикл `while` — это цикл с предусловием. Перед очередной итерацией проверяется условие, и если оно истинно, то цикл продолжается.

```
while (условие) { ...; }
```
Например,
```
int i = 5;
while (i > 0) {
  i = i - 2;
  print ("lol");
}
```
В результате выполнения программы слово `lol` будет выведено на экран трижды.

#### Логические операторы ####

* логичское или - `or`. Логический оператор `or` возвращает логическое значение 1, если один или оба операнда выполняются, и возвращает 0 в противном случае.
* логичиеское и - `and`. Логический оператор `and` возвращает логическое значение 1, если оба операнда выполняются, и возвращает 0 в противном случае.

### Примеры ###

В папке 'tests' вы можете обнаружить несколько примеров рабочих программ. Рассмотрим несколько из них.

test_01.das

```
real a[10];

print("enter 10 real numbers: ");

for(int i = 0; i < 10; i = i + 1)
	read(a[i]);

for(int i = 0; i < 9; i = i + 1)
	for(int j = 0; j < 9; j = j + 1){
		if (a[j] > a[j+1]){
			int t = a[j];
			a[j] = a[j+1];
			a[j+1] = t;
		}
		
	};

println("sorted 10 real numbers: ");

for(int i = 0; i < 10; i = i + 1)
	print(a[i], " ");
```

В строке ```real a[10];``` объявляется пустой вещественный массив 'a' с 10 ячейками. После чего происходит вывод сообщения для пользователя - необходимо ввести 10 вещественных чисел.


В цикле ниже последовательно считываются 10 чисел, вводимых пользователем через консоль.
```
for(int i = 0; i < 10; i = i + 1)
	read(a[i]);
```
Затем просиходит примитивная сортировка пузырьком:

```
for(int i = 0; i < 9; i = i + 1)
	for(int j = 0; j < 9; j = j + 1){
		if (a[j] > a[j+1]){
			int t = a[j];
			a[j] = a[j+1];
			a[j+1] = t;
		}
		
	};
```
Заключающим дествием выводится сообщение о том, что 10 чисел отсортированы 
```
println("sorted 10 real numbers: ");
```
и сам отсортированный массив
```
for(int i = 0; i < 10; i = i + 1)
	print(a[i], " ");
```

test_10.das

В данном тесте рассматривается алгоритм бинарного возведения в степень.

```
int number;
int power;

print("enter number to power: ");
read(number);

print("enter power: ");
read(power);

int res = 1;

print(number, " in power ", power , " is :");

while (power > 0) {
	if (power % 2 == 1)
		res = res * number;
	number = number * number;
	power = power / 2;
}

print(res);
```
В строках ниже объявляются переменные ```number``` - число для возведения в степень, и ```power``` - степень в которую число будет возведено. Далее в кольсоль вводятся сообщения, сообщающие пользователю о том, какое число нужно ввести и происходит считывание соответсвующих переменных из консоли.

```
int number;
int power;

print("enter number to power: ");
read(number);

print("enter power: ");
read(power);
```
Далее инициализируется результурующая переменная ```res```. Заранее выводится сообщение 'число number в степени ```power``` это:' и начинается расчет резултрующей переменной с помощью алгоритма бинарного возведения в степенью

```
int res = 1;

print(number, " in power ", power , " is :");

while (power > 0) {
	if (power % 2 == 1)
		res = res * number;
	number = number * number;
	power = power / 2;
}
```
В заключении выводится ответ на задачу:
```
print(res);
```

### Ошибки ###

1) использование нашего компилятора не в учебных целях

## FAQ ##

Мы будем сильно удивлены, если у кого-то возникнет вопрос! Но это даже хорошо, ведь мы наконец сможем пополнить это блок. Он больше не будет зря занимать здесь место. 
