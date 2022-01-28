# Парсинг методом рекурсивного спуска (top-down parsing)

Парсер, использующий $LL(1)$-грамматику, будет называться $LL(1)$-парсер.

Грамматика, используемая в данном парсере:

```
stmt -> expr | ε
expr -> term | term + expr
term -> fact | fact * term
fact -> NUM | (expr)
```

($\varepsilon$ – пустое множество)

Наша цель – составить из соответствующих терминалов и нетерминалов самый 
верхний символ грамматики (`stmt`).