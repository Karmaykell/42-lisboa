# Exames da piscine — como funcionam e como treinar

Reconstruído de memória. Formato, pool e regras variam por campus e por ano; **confirme com o aluno o que ele viu no exam00** e ajuste este arquivo.

## O ambiente

- Máquina do cluster em modo exame: só **Vim/Emacs**, terminal, `gcc`/`cc`. **Sem internet, sem norminette, sem mini-moulinette, sem os arquivos dele.**
- Um programa (`examshell`) mostra o enunciado do exercício atual. Ele escreve em `~/rendu/<nome_do_exercicio>/`, com o nome de arquivo pedido.
- `grademe` corrige na hora: compila com `-Wall -Wextra -Werror` (uma warning = KO) e roda testes de borda. Devolve só **OK/KO** — às vezes mostra o teste que falhou, às vezes não.
- KO → o mesmo exercício de novo (às vezes outro do mesmo nível). Sem penalidade além do tempo.
- **Norma não é avaliada nos exames da piscine.** Mas `-Werror` reprova: variável não usada, parâmetro não usado, função não-void sem `return`, comparação de tipos incompatíveis, declaração implícita (falta `#include`).
- Exames: `exam00`, `exam01`, `exam02` (níveis 1–3 aproximadamente) e o **exame final** (níveis 1–4, ~4 horas). Cada nível sorteia **um** exercício do pool daquele nível. Passar de nível = OK no sorteado.

## O que muda em relação ao dia a dia

- Muitos exercícios do exame são **programas** (`main` com `argc/argv`) e têm a mesma cláusula: *"se o número de argumentos não for 1, mostra uma quebra de linha"* (ou `\n` só). Isso é **um caso de teste** — trate primeiro, com `if (argc != 2) { write(1, "\n", 1); return (0); }`.
- Só `write`, `malloc`, `free` (e às vezes `read`) são permitidos. Sem `printf`. Ele precisa ter `putchar`, `putstr`, `strlen`, `putnbr` **na memória dos dedos**.
- Os exercícios são pequenos (10–40 linhas), mas o corretor testa borda: string vazia, só espaços, `INT_MIN`, `0`, lista vazia, `NULL`.
- Erro de digitação (`retutrn`, `;` faltando) custa uma tentativa. Compilar **antes** de submeter é obrigatório.

## Pool aproximado por nível

Um exercício por nível é sorteado. Descrições de uma linha; o enunciado completo ele vê no exame.

### Nível 1 — funções básicas / programas de uma passada
- `ft_putstr(char *str)`, `ft_strlen`, `ft_swap`, `ft_strcpy`, `ft_strcmp`, `ft_strrev(char *str)` (inverte no lugar, retorna `str`)
- `first_word` — imprime a primeira palavra (espaços/tabs são separadores); sem arg ou arg errado → `\n`
- `last_word` — última palavra
- `repeat_alpha` — `abc` → `abbccc` (letra repetida pelo índice no alfabeto; não-letras 1 vez)
- `rev_print` — imprime o arg invertido
- `rot13` / `rotone` — cifra de César 13 / 1
- `ulstr` — inverte maiúscula↔minúscula
- `search_and_replace` — `./a.out "abc" a z` → `zbc`; args 2 e 3 devem ter 1 char
- `fizzbuzz` — 1..100
- `ft_putnbr` — sem `printf`, cuidado INT_MIN
- `ft_atoi` — versão simples (espaços, um sinal, dígitos)
- `print_bits(unsigned char)` — 8 bits; `reverse_bits`; `swap_bits` (4 primeiros com 4 últimos)
- `max(int *tab, unsigned int len)` — 0 se vazio
- `ft_range(int start, int end)` — array com malloc, **incluindo end**, funciona decrescente
- `ft_rrange` — reverso
- `alpha_mirror` — `a↔z`, `b↔y`
- `camel_to_snake` / `snake_to_camel`
- `do_op` — `./a.out 42 + 2` → `44` (ints; sem tratar divisão por zero em alguns)
- `is_power_of_2(unsigned int n)`
- `ft_strdup`
- `str_capitalizer` — primeira letra de cada palavra maiúscula, resto minúscula
- `wdmatch` — `./a.out "faya" "fgvvfdxcacpolhyghbreda"` → `faya` se a 1ª pode ser formada da 2ª mantendo ordem
- `rostring` — imprime a string com a primeira palavra movida pro fim, um espaço entre palavras
- `inter` / `union` — chars comuns / união de duas strings, sem repetir, na ordem de aparição (tabela de 256 vistos)
- `hidenp` — `./a.out "fgex.;" "tyf34gdgf;'ektufjhgdgex.;.;rtjynpo;"` → `1` se a 1ª é subsequência da 2ª
- `paramsum`, `print_hex` (arg decimal → hexa minúsculo), `tab_mult` (tabuada)
- `lcm`, `pgcd` (gcd), `add_prime_sum` (soma dos primos até n; `0` se arg inválido)
- `expand_str` — 3 espaços entre palavras, sem espaços nas pontas
- `epur_str` — 1 espaço entre palavras
- `ft_itoa`, `ft_strcspn`, `ft_strspn`, `ft_strpbrk`, `ft_strrev`
- `sort_int_tab(int *tab, unsigned int size)`

### Nível 2 — strings com malloc, ponteiros, listas simples
- `ft_split(char *str)` — separadores espaço/tab/newline; retorna `char **` terminado em NULL
- `ft_strdup`, `ft_strcpy`, `ft_atoi_base(const char *str, int str_base)` — bases 2..16, com sinal
- `ft_list_size(t_list *begin_list)`, `ft_list_foreach`, `ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())`
- `sort_list(t_list *lst, int (*cmp)(int, int))` — ordena trocando `data`
- `ft_rrange`, `ft_range`
- `flood_fill(char **tab, t_point size, t_point begin)` — recursivo, troca por `F` os vizinhos com o mesmo char
- `rstr_capitalizer`, `str_capitalizer`
- `print_memory`, `ft_strcat`, `ft_strncmp`, `ft_strstr`, `ft_strlcat`, `ft_strlcpy`
- `wdmatch`, `inter`, `union`, `hidenp`
- `tab_mult`, `add_prime_sum`, `pgcd`, `lcm`
- `is_power_of_2`, `print_bits`, `reverse_bits`, `swap_bits`

### Nível 3 — programas com parsing e lógica
- `ft_split` (versão com charset ou com espaços), `ft_itoa`, `ft_atoi_base`
- `flood_fill`, `sort_list`, `ft_list_remove_if`, `ft_list_foreach`
- `paramsum`, `expand_str`, `epur_str`, `str_capitalizer`, `rostring`
- `pgcd`, `lcm`, `add_prime_sum`, `print_hex`
- `do_op` completo, `hidenp`, `wdmatch`

### Nível 4 (só no final)
- `ft_split`, `flood_fill`, `sort_list`, `ft_list_remove_if`, `ft_atoi_base`, `ft_itoa`
- `rev_wstr` — palavras em ordem inversa
- `fprime` — fatores primos `./a.out 225` → `3*3*5*5`
- `options` — parse de flags `-abc` pra bits
- `tab_mult`, `pgcd`

(A distribuição real por nível varia; o que importa é que os mesmos ~40 nomes aparecem em todos os exames.)

## Roteiro de simulado (`/42-tutor exame <nome>`)

1. Você dá **só** o enunciado no formato do exame (Assignment name / Expected files / Allowed functions / texto / exemplos com `$>./a.out ... | cat -e`). Sem dicas.
2. Ele cria a pasta e o arquivo com o nome exigido, de preferência no Vim, sem olhar código antigo. Tempo sugerido: 20–30 min por exercício de nível 1–2, 40 por nível 3–4.
3. Ele diz "grademe". Você compila com `cc -Wall -Wextra -Werror` (o `main` dele pra programas; um `main` seu pra funções) e roda a bateria de bordas. Responde **como a máquina**: `OK` ou `KO` + o caso que falhou (entrada, esperado, obtido). Nada de explicação.
4. KO → ele tenta de novo. Máximo 3 tentativas; depois vira tutor.
5. Depois do OK: revisão curta — o que ele demorou, o que esqueceu, uma regra pra levar. Anota em `traps.md` se for novo.

## Bateria de bordas que o corretor usa (aplique nos simulados)

- Programas: 0 args, 2+ args, arg vazio `""`, só espaços `"   "`, espaços nas pontas, tabs, string de 1 char.
- Números: `0`, `1`, `-1`, `INT_MAX`, `INT_MIN`, `"+42"`, `"  -42"`, `"42abc"`, `"abc"`.
- Strings: vazia, sem o padrão, padrão no início/fim, padrão repetido, maiúsculas/minúsculas misturadas, chars não-alfa.
- Listas: `NULL`, um nó, remover a cabeça, remover todos, remover consecutivos.
- Arrays: `size 0`, `size 1`, todos iguais, já ordenado, ordem inversa.
- malloc: `-fsanitize=address` ligado; `free` de tudo; sem leitura fora do bloco.

## O que ele precisa ter decorado antes do final

Sem olhar, em menos de 2 minutos cada: `ft_putchar`, `ft_putstr`, `ft_strlen`, `ft_putnbr` (com INT_MIN), `ft_atoi` (espaços + sinais), `ft_strcmp`, `ft_strcpy`, `ft_strdup`, bubble sort de `int *`, bubble sort de `char **`, `is_space`, o esqueleto de programa com `if (argc != 2)`, percorrer `t_list`, `ft_split` por espaços.
