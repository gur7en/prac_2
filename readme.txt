Вариант 15
Курсы валют: название валют (2 строки), курс (дробное), дата
Применён кодстайл WebKit

Диаграмма классов (см. class_diagramm.png)
 ,--------------. 
 |Date          | 
 |--------------| 
 |+ void read() | 
 |+ void print()| 
 |+ int check() | 
 |- int year    | 
 |- int month   | 
 |- int day     | 
 |              | 
 `--------------' 
         |        
         |        
,----------------.
|Rate            |
|----------------|
|+ void read()   |
|+ void print()  |
|- string source |
|- string destin |
|- double rate   |
|- void read_do()|
`----------------'
