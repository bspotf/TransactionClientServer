Клиент-серверное приложение 

1. Написать TCP транспорт

2. Формируется vector<string>, в котором будут записаны транзакции(например 10 транзакций). 
В двух пакетах, нужно передать данные транзакции в транспорт, для рассылки в дальнейшие места.

3. Так же, должно происходить логирование возможных ошибок в файл.

4. Продумать функцию, которая будет брать каждую строку вектора, разбивать ее на переменные 
и передавать их в другой любой сервис, где они будут храниться. 

Пример транзакции: "sfsg4d|gdfgw1|354:258|cs|1|".