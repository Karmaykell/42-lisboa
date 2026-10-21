# Piscine C — banco de exercícios

Reconstruído de memória a partir dos subjects clássicos da 42. **Sempre confirme com o enunciado que o aluno colar** — nomes e detalhes mudam entre campi e anos. Use isto pra: reconhecer o exercício, nomear o conceito novo, antecipar armadilhas, e apontar o que ele já fez que serve de peça.

Formato: `exNN nome — protótipo · ideia · armadilhas · reaproveita`.

Regra geral de pontuação: exercícios valem igual dentro do módulo e são corrigidos **em ordem**; o primeiro que falha zera os seguintes. Um exercício que **não existe** não bloqueia (a pasta ausente é pulada) — um que existe e falha, bloqueia.

---

## C00 — `write`, loops, ASCII
Conceito novo: só `write(1, &c, 1)`; tudo é caractere; contar de `'0'` a `'9'` é aritmética.

- ex00 `ft_putchar(char c)` · `write(1, &c, 1)` · o `&` — write quer endereço.
- ex01 `ft_print_alphabet(void)` · loop `'a'`..`'z'`.
- ex02 `ft_print_reverse_alphabet(void)` · loop decrescente.
- ex03 `ft_print_numbers(void)` · `'0'`..`'9'`.
- ex04 `ft_is_negative(int n)` · imprime `N` ou `P` · zero é `P`.
- ex05 `ft_print_comb(void)` · todas as combinações de 3 dígitos crescentes `012`..`789`, separadas por `, ` · sem vírgula depois do último (`789`); 3 loops aninhados começando em `a+1`, `b+1`.
- ex06 `ft_print_comb2(void)` · pares `00 01`..`98 99` · idem, com espaço no meio.
- ex07 `ft_putnbr(int nb)` · recursivo: `if (nb < 0) { '-' ; nb = -nb }` **estoura no INT_MIN** — trate com `long` ou imprimindo `-2147483648` à parte / trabalhando com negativo.
- ex08 `ft_print_combn(int n)` · generalização do ex05 · recursão/backtracking (é a versão fácil do ten_queens).

## C01 — ponteiros, arrays
Conceito novo: `*` pra modificar a variável de quem chamou; array = endereço + índice.

- ex00 `ft_ft(int *nbr)` · `*nbr = 42`.
- ex01 `ft_ultimate_ft(int *********nbr)` · nove `*` — conta os níveis.
- ex02 `ft_swap(int *a, int *b)` · variável temporária.
- ex03 `ft_div_mod(int a, int b, int *div, int *mod)` · escreve nos dois ponteiros.
- ex04 `ft_ultimate_div_mod(int *a, int *b)` · `*a = *a / *b`, cuidado com a ordem (guarde o antigo antes).
- ex05 `ft_putstr(char *str)` · loop até `'\0'`.
- ex06 `ft_strlen(char *str)` · **não conta o `'\0'`**.
- ex07 `ft_rev_int_tab(int *tab, int size)` · troca `tab[i]` com `tab[size-1-i]` até o meio.
- ex08 `ft_sort_int_tab(int *tab, int size)` · bubble sort · ponte direta pro `ft_sort_params` (C06) e pro `sort_int_tab` do exame.

## C02 — strings e classes de caracteres
Conceito novo: string vazia é "verdadeira" (retorna 1) nos `is_*`; ASCII como faixas numéricas.

- ex00 `ft_strcpy(char *dest, char *src)` · copia até e **incluindo** `'\0'`; retorna `dest`.
- ex01 `ft_strncpy(dest, src, n)` · copia até `n`; se `src` menor, preenche com `'\0'`; se maior, **não** termina com `'\0'` (comportamento do strncpy real).
- ex02–06 `ft_str_is_alpha/numeric/lowercase/uppercase/printable` · retorna 1 pra string vazia · printable é `32..126`.
- ex07 `ft_strupcase` / ex08 `ft_strlowcase` · `c - 32` / `c + 32`.
- ex09 `ft_strcapitalize` · primeira letra de cada palavra maiúscula; palavra = após não-alfanumérico; dígitos contam como parte da palavra (`"1e"` fica `"1e"`).
- ex10 `ft_strlcpy(dest, src, size)` · retorna `strlen(src)`; copia no máximo `size-1` e sempre termina com `'\0'` se `size > 0`.
- ex11 `ft_putstr_non_printable` · não imprimíveis viram `\xx` hexa minúsculo.
- ex12 `ft_print_memory(void *addr, unsigned size)` · endereços em hexa, 16 bytes por linha, coluna de hexa + coluna de caracteres · `unsigned char` pra não ter sinal.

## C03 — comparação e concatenação
Conceito novo: `strcmp` devolve a diferença ASCII no primeiro char diferente; `unsigned char` na comparação.

- ex00 `ft_strcmp(s1, s2)` · `while (s1[i] && s1[i] == s2[i]) i++; return s1[i] - s2[i]` (cast `unsigned char` pra bater com a libc).
- ex01 `ft_strncmp(s1, s2, n)` · para em `n`.
- ex02 `ft_strcat(dest, src)` · acha o fim de `dest`, copia `src`, `'\0'` · usado no strjoin (C07).
- ex03 `ft_strncat(dest, src, nb)`.
- ex04 `ft_strstr(str, to_find)` · `to_find` vazio → retorna `str`; dois índices, reinicia no falso positivo.
- ex05 `ft_strlcat(dest, src, size)` · retorna `dest_len + src_len` (o tamanho que *tentou* criar); se `size <= dest_len` retorna `size + src_len`.

## C04 — números ↔ strings, bases
Conceito novo: `atoi` com espaços/sinais; base como string; recursão pra imprimir.

- ex00 `ft_strlen` · ex01 `ft_putstr` · ex02 `ft_putnbr` (INT_MIN!).
- ex03 `ft_atoi(char *str)` · pula espaços (`' '`, `\t\n\v\f\r`), conta os `-` (ímpar = negativo), `+` também é sinal, para no primeiro não-dígito · `"  ---+--+1234ab567"` → `-1234`.
- ex04 `ft_putnbr_base(int nbr, char *base)` · valida base (≥2 chars, sem repetidos, sem `+`/`-`/espaços; senão não imprime nada) · recursão com `nbr / len` e `base[nbr % len]` · INT_MIN: trabalhe com `long` ou com negativo.
- ex05 `ft_atoi_base(char *str, char *base)` · valida base; mesma regra de espaços/sinais do atoi; "qual índice esse char tem na base?" vira função auxiliar.

## C05 — recursão, matemática
Conceito novo: caso base + caso recursivo; dois casos base quando a fórmula olha dois passos atrás.

- ex00 `ft_iterative_factorial(int nb)` · `nb < 0` → 0; `0!` = 1; `result = 1; while (nb > 0) result *= nb--`.
- ex01 `ft_recursive_factorial` · base `nb == 0 → 1`; `nb * f(nb-1)`.
- ex02 `ft_iterative_power(nb, power)` · `power < 0` → 0; `0^0` = 1 (sai natural com `result = 1` e loop 0 vezes).
- ex03 `ft_recursive_power` · base `power == 0 → 1`; `nb * f(nb, power-1)`.
- ex04 `ft_fibonacci(int index)` · `index < 0` → -1; bases `0 → 0`, `1 → 1`; `f(n-1) + f(n-2)`.
- ex05 `ft_sqrt(int nb)` · raiz inteira ou 0; `while (i * i < nb) i++` · **overflow**: `i * i` estoura pra `nb` perto de INT_MAX — use `i <= 46340` ou `long`.
- ex06 `ft_is_prime(int nb)` · `nb <= 1` → 0; divisores de 2 até `i * i <= nb` (a otimização da raiz) · o mini não cobre tudo: teste `2`, `3`, `4`, `INT_MAX` (primo), performance.
- ex07 `ft_find_next_prime(int nb)` · `while (!is_prime(nb)) nb++` · `nb <= 2` → 2 · INT_MAX é primo, então não passa dele.
- ex08 `ft_ten_queens_puzzle(void)` · backtracking coluna a coluna; array `positions[10]`; conflito de linha e diagonal (`|dl| == |dc|`); imprime cada solução como 10 dígitos + `\n`; retorna 724 · é bônus em muitos campi.

## C06 — `argc`/`argv`, programas
Conceito novo: `main(int argc, char **argv)`; `argv[0]` é o programa; `argv[argc]` é `NULL`; tudo é texto.

- ex00 `ft_print_program_name` · `argv[0]` + `\n`.
- ex01 `ft_print_params` · `argv[1..argc-1]`, um por linha.
- ex02 `ft_rev_params` · `i = argc - 1; while (i > 0)`.
- ex03 `ft_sort_params` · bubble sort trocando **ponteiros** (`char *tmp`) com `ft_strcmp`; imprime ordenado (ASCII: maiúsculas antes de minúsculas).

## C07 — `malloc`
Conceito novo: heap, posse (quem aloca entrega; quem recebe libera), `NULL` do malloc, ponteiro duplo pra "devolver por parâmetro".

- ex00 `ft_strdup(char *src)` · `malloc(len + 1)`, checa `NULL`, copia, `'\0'`.
- ex01 `ft_range(int min, int max)` · `min >= max` → `NULL`; `malloc((max-min) * sizeof(int))`; `tab[i] = min + i`.
- ex02 `ft_ultimate_range(int **range, int min, int max)` · escreve em `*range`; retorna o **tamanho** (0 se `min >= max` com `*range = NULL`; -1 se malloc falhou) — o subject em PT perdeu a palavra "tamanho".
- ex03 `ft_strjoin(int size, char **strs, char *sep)` · `size == 0` → `malloc(1)` com `'\0'` (liberável); total = Σ`strlen(strs[i])` + `(size-1) * strlen(sep)` + 1; `strcat` em loop com `if (i < size - 1)` pro sep · 4 funções: strlen, total_len, strcat, join.
- ex04 `ft_convert_base(char *nbr, char *base_from, char *base_to)` · **dois arquivos** (`ft_convert_base.c` + `ft_convert_base2.c`, funções do 2 sem `static`, protótipos no 1) · valida as duas bases → `NULL`; `atoi_base` (C04) → `int`; conta dígitos em `base_to`; `malloc(dígitos + sinal + 1)`; preenche de trás pra frente · `"0"` → `"0"`; INT_MIN: trabalhe com negativo ou `long`; só um `-`, sem `+`/espaços na saída.
- ex05 `ft_split(char *str, char *charset)` · retorna `char **` terminado em `NULL`; palavras = trechos entre chars do charset; conta palavras → `malloc((n+1) * sizeof(char *))`; pra cada palavra, `malloc(len+1)` + copia · `""` e string só de separadores → `[NULL]` · é o exercício mais reaproveitado do common core (libft, minishell, push_swap).

## C08 — headers, macros, structs
Conceito novo: `#ifndef/#define/#endif` (include guard), `typedef struct`, `#define` de constantes/macros, ponteiro pra struct e `->`.

- ex00 `ft.h` · protótipos de putchar, swap, putstr, strlen, strcmp com guard.
- ex01 `ft_boolean.h` · `typedef int t_bool; #define TRUE 1; FALSE 0; EVEN(nbr) ((nbr) % 2 == 0)` e strings pra o main dado · parênteses na macro.
- ex02 `ft_abs.h` · `#define ABS(Value) ((Value) < 0 ? -(Value) : (Value))` · **parênteses em tudo**; `ABS(x++)` avalia duas vezes — cite como curiosidade.
- ex03 `ft_point.h` · `typedef struct s_point { int x; int y; } t_point;` e `set_point(t_point *point)` com `point->x = 42`.
- ex04 `ft_strs_to_tab(int ac, char **av)` · retorna `t_stock_str *` (`size`, `str`, `copy`), último elemento com `str = 0`; `copy` via strdup; `malloc((ac+1) * sizeof(t_stock_str))`.
- ex05 `ft_show_tab(struct s_stock_str *par)` · imprime `str`, `size`, `copy` até `str == 0`.

## C09 — bibliotecas estáticas, Makefile
Conceito novo: `ar rc libft.a *.o`; Makefile com `NAME`, `all`, `clean`, `fclean`, `re`; variáveis `$(CC) $(CFLAGS)`; `.PHONY`.

- ex00 `libft_creator.sh` · script que compila `*.c` com `-Wall -Wextra -Werror`, `ar rc libft.a`, `ranlib`.
- ex01 `Makefile` · estrutura `srcs/`, `includes/`; regras obrigatórias; **não relinka** (`$(NAME): $(OBJS)`); `clean` remove `.o`, `fclean` remove também a `.a`.
- ex02 `ft_split(char *str, char *charset)` · igual ao C07 ex05.

## C10 — programas com arquivos
Conceito novo: `open`/`read`/`close`, `errno`/`strerror`, argumentos de linha de comando, `write(2, ...)` pra stderr.

- ex00 `ft_display_file` · 1 arg exato: sem arg → `File name missing.`; 2+ → `Too many arguments.` (ambos em stderr); `open`, `read` em loop com buffer, `write`; erro → `Cannot read file.`.
- ex01 `ft_cat` · comporta como `cat`: vários arquivos, `-` ou sem args lê stdin; erros no formato `ft_cat: <arquivo>: <strerror(errno)>` e continua com os próximos.
- ex02 `ft_tail` (nem sempre presente) · `-c N` · buffer circular ou ler tudo.
- ex03 `ft_hexdump` · formato do `hexdump -C`, opção `-C`; linhas repetidas viram `*`.

## C11 — ponteiros de função
Conceito novo: `int (*f)(int)`; passar função como argumento; `f(x)` ou `(*f)(x)`.

- ex00 `ft_foreach(int *tab, int length, void (*f)(int))`.
- ex01 `ft_map(int *tab, int length, int (*f)(int))` · retorna array novo com `malloc`.
- ex02 `ft_any(char **tab, int (*f)(char*))` · 1 se algum satisfaz; `tab` termina em `NULL`.
- ex03 `ft_count_if(char **tab, int length, int (*f)(char*))`.
- ex04 `ft_is_sort(int *tab, int length, int (*f)(int, int))` · 1 se crescente **ou** decrescente (ordenado em qualquer direção).
- ex05 `ft_do_op` (programa) · `./a.out 42 + 2` → `44`; `/` e `%` por zero → `Stop : division by zero` / `Stop : modulo by zero`; operador inválido → `0`; usa atoi e um array de ponteiros de função indexado pelo operador.
- ex06 `ft_sort_string_tab(char **tab)` · bubble com strcmp, `tab` terminado em `NULL`.
- ex07 `ft_advanced_sort_string_tab(char **tab, int (*cmp)(char *, char *))`.

## C12 — listas encadeadas
Conceito novo: `t_list { void *data; t_list *next; }`; percorrer com `while (lst)`; `t_list **begin_list` pra modificar a cabeça; `free` de cada nó.

- ex00 `ft_create_elem(void *data)` · malloc, `next = NULL`.
- ex01 `ft_list_push_front(t_list **begin_list, void *data)`.
- ex02 `ft_list_size(t_list *begin_list)`.
- ex03 `ft_list_last(t_list *begin_list)`.
- ex04 `ft_list_push_back(t_list **begin_list, void *data)` · lista vazia → vira o primeiro.
- ex05 `ft_list_push_strs(int size, char **strs)` · push_front de cada (ordem inversa).
- ex06 `ft_list_clear(t_list *begin_list, void (*free_fct)(void *))` · libera `data` com `free_fct` e o nó com `free`; guarde o `next` antes de liberar.
- ex07 `ft_list_at(t_list *begin_list, unsigned int nbr)` · retorna `NULL` se não existe.
- ex08 `ft_list_reverse(t_list **begin_list)` · três ponteiros (`prev`, `cur`, `next`).
- ex09 `ft_list_foreach(t_list *begin_list, void (*f)(void *))`.
- ex10 `ft_list_foreach_if(begin_list, f, data_ref, cmp)`.
- ex11 `ft_list_find(begin_list, data_ref, cmp)` · retorna o nó.
- ex12 `ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)(), void (*free_fct)(void *))` · o mais cobrado no exame: cuidado com remover a cabeça e com nós consecutivos.
- ex13 `ft_list_merge(t_list **begin_list1, t_list *begin_list2)`.
- ex14 `ft_list_sort(t_list **begin_list, int (*cmp)())` · troca `data`, não nós (mais simples).
- ex15 `ft_list_reverse_fun(t_list *begin_list)` · inverte trocando data.
- ex16 `ft_list_merge/sorted_insert` variantes.

## C13 — árvores binárias
Conceito novo: `t_btree { t_btree *left, *right; void *item; }`; recursão natural; percursos prefix/infix/suffix.

- ex00 `btree_create_node(void *item)`.
- ex01 `btree_apply_prefix(t_btree *root, void (*applyf)(void *))` · raiz, esq, dir.
- ex02 `btree_apply_infix` · esq, raiz, dir (em árvore de busca = ordenado).
- ex03 `btree_apply_suffix` · esq, dir, raiz (ordem certa pra liberar).
- ex04 `btree_insert_data(t_btree **root, void *item, int (*cmpf)(void *, void *))` · `< 0` vai pra esquerda; iguais pra esquerda (ou como o subject disser).
- ex05 `btree_search_item(root, data_ref, cmpf)` · busca em infix (o subject pede infix, não busca binária).
- ex06 `btree_level_count(t_btree *root)` · `1 + max(esq, dir)`, `NULL` → 0.
- ex07 `btree_apply_by_level(root, applyf(void *item, int current_level, int is_first_elem))` · BFS: precisa de fila ou de "aplica no nível N" repetido por nível.

---

## Pontes entre módulos (use pra dizer "você já fez isso")

- C00 putchar/putnbr → C04 putnbr_base → C07 convert_base
- C01 swap → C06 sort_params (troca ponteiros) → C12 list_sort (troca data)
- C01 strlen/putstr → C02/C03 tudo → C07 strdup/strjoin
- C01 sort_int_tab → C06 sort_params → C11 sort_string_tab → exame sort_int_tab/sort_list
- C03 strcmp → C06 sort_params → C11 → C12 find/remove_if
- C04 atoi/atoi_base → C07 convert_base → C11 do_op → exame ft_atoi_base
- C05 recursão → C08 combn/ten_queens → C13 árvores
- C07 malloc/split → C09 split → libft → get_next_line → minishell
- C12 `t_list **` → libft bonus → push_swap
