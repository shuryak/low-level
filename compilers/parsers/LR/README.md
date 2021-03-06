# LR-парсер

LR-грамматика предполагает, что парсер будет двигаться по синтаксическому 
дереву снизу вверх (bottom-up parsing).

## Принцип переноса-свёртки

При $LR(k)$-анализе применяется метод "*перенос-свёртка*" (*shift/reduce*):

1. Лексический анализатор читает последовательно символы входной строки до тех 
   пор, пока не накопится цепочка, совпадающая с правой частью какого-нибудь из 
   правил грамматики. Рассмотренные символы переносим в стек (операция 
   "*перенос*" (*shift*)).
2. Все символы совпадающей цепочки извлекаются из стека и на их место 
   помещается нетерминал, находящийся в левой части этого правила грамматики 
   (операция "*свёртка*" (*reduce*)).

Операция "перенос" сохраняет значение терминала в стек парсинга и запрашивает 
у лексического анализатора следующий токен.

Операция "свёртка" извлекает из стека парсинга один или несколько символов, 
находящихся в продукции справа и на их место помещает символ, находящийся в 
продукции слева.

## Структура

- Входная строка
- Стек парсинга (parse stack)
- Управляющая таблица (reduction table)
- Автомат для запоминания информации о текущем состоянии стека (value stack)
