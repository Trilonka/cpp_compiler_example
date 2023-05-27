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

И извлекайте его (распаковка на*й):
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

* целочисленный `int`. 

* тип с плавающей точкой `real`. 

```
real r = 21.3;
```

Числа могут принимать как положительные, так и отрицательные значения.

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

Присвоить значения элементам массива возможно только непосредствено указав номер элемента. 

```
a[0] = 0; a[1] = 1; 
```

Для ускорения этого процесса советуем воспользоваться оператором `for`.

```
for (int i = 0; i < 2; i = i + 1)
 a[i] = i;
```

p.s. ускорение заключается в том, что мы пока не уверены, скомпилируется ли этот код.

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

#### Вывод инфомрации ####

Для вывода данных Вы можете использовать ключевое слово `print`.

```
int a = 10;
print(a);
```

В результате выполнения этой программы в консоли появится число 10.

### Использование ключевых слов ###

Обсудим некоторые встроенные операторы.

#### Оператор `if` ####

Условный оператор `if` - самый простой оператор для принятия решения. Он используется для определения того, будет ли выполняться определенный оператор или блок операторов, т.е. если определенное условие истинно, тогда блок оператора выполняется, иначе - нет.

```
if (условие) { ...; }
```

#### Оператор `else` ####

`else` используется, чтобы сказать компьютеру, какие инструкции нужно выполнить, если проверяемое утверждение было ложным. Программа сначала проверит первое условие и, если оно ложно, выполняются инструкции внутри `else`, поэтому оно всегда должно стоять в конце.

```
if (условие) { ...; } else { ...; }
```

#### Оператор `for` ####

Используйте инструкцию `for` для создания циклов, которые должны выполняться указанное количество раз. Выполняет оператор повторно до тех пор, пока условное значение не станет false. 

```
for ( ; ; ) { ...; }
```

#### Оператор `while` ####

Цикл `while` — это цикл с предусловием. Перед очередной итерацией проверяется условие, и если оно истинно, то цикл продолжается.

```
while (условие) { ...; }
```

#### Логические операторы ####

* логичское или - `or`. Логический оператор `or` возвращает логическое значение 1, если один или оба операнда выполняются, и возвращает 0 в противном случае.
* логичиеское и - `and`. Логический оператор `and` возвращает логическое значение 1, если оба операнда выполняются, и возвращает 0 в противном случае.

### Ошибки ###

1) использование нашего компилятора не в учебных целях

## FAQ ##

Мы будем сильно удивлены, если у кого-то возникнет вопрос! Но это даже хорошо, ведь мы наконец сможем пополнить это блок. Он больше не будет зря занимать здесь место. 
