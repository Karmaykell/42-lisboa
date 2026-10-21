# Armadilhas recorrentes deste aluno + checklist "antes de dizer terminei"

Atualize quando surgir um erro novo que se repete. Cada item tem: o erro, como reconhecer, a regra de bolso que ele já ouviu (reuse o mesmo nome).

## Erros que ele já cometeu (e que voltam)

### Declaração × chamada
- **Erro:** escrever tipo na chamada (`ft_strcat(char *endstr, char *strs[i])`), ou tirar o tipo da declaração (`void f(argv)`). Voltou 4 vezes em 2 dias.
- **Sinal:** `error: expected expression` na linha da chamada; `subscripted value is not an array` quando falta tipo na declaração.
- **Regra:** *"declaração = tipo + nome; chamada = só o nome."* Mostrar o próprio `ft_is_prime(nb)` dele como exemplo.

### Endereço × valor
- **Erro:** `write(1, argv[0][i], 1)` (passa a letra), `write(1, '\n', 1)` (aspas simples = número), `while (&argv[0][i] != '\0')` (compara endereço com letra), `if (*memory == NULL)`.
- **Sinal:** `incompatible integer to pointer conversion`, `comparing a pointer to a null character constant`.
- **Regra:** *"`write` quer endereço: `&c` pra um char, `"texto"` já é endereço. Comparação com `'\0'` quer a letra: sem `&`."* E: *"`*` na frente lê o conteúdo; só use quando quer o que está dentro."*

### `'\0'` × `NULL`
- **Erro:** `while (argv[i] != '\0')` (fim da lista de strings), `*range[i] = '\0'` num array de int.
- **Regra:** *"`'\0'` termina string (chars). `NULL` termina lista de ponteiros (`argv`). Array de `int` não termina com nada — precisa do tamanho."*

### Índice fora da lista
- **Erro:** `i = argc` (→ `argv[argc]` é `NULL`, segfault 139), `i <= size` (lê `strs[size]`), `while (i < max)` num bloco de `max - min` (escreve fora do malloc).
- **Sinal:** exit code 139; AddressSanitizer `heap-buffer-overflow`.
- **Regra:** *"último índice válido é `tamanho - 1`; loop é `< tamanho`."* Rastrear com `argc = 4`.

### Valor inicial do acumulador
- **Erro:** `result = 0` antes de multiplicar (fatorial, potência); ou nenhum valor (lixo).
- **Regra:** *"elemento neutro: soma começa em 0, produto começa em 1. Variável sem valor em C é lixo, não `undefined`."*

### Acumular × recalcular
- **Erro:** `result = nb * nb`, `result = nb * nb - 1`, `result = result + nb * nb` — não usa o `result` anterior ou usa a operação errada.
- **Regra:** *"acumular é `result = result OP x`. Potência é multiplicação repetida, não soma."* Rastrear com `2^3`.

### Loop sem avanço / condição errada
- **Erro:** `while (i < nb - 1)` sem `i++` (infinito); `while (i < min - max)` (negativo, nunca roda); `while (i < ft_total_len(...))` contando letras onde `i` conta strings.
- **Regra:** *"o que o `i` conta? A condição tem que estar na mesma unidade."*

### Retorno invertido / faltando
- **Erro:** `return (1)` ao achar divisor (é_primo); `return (*range)` quando a função devolve `int`; `return ("error")` de um `strdup`; função `int` sem `return` em todos os caminhos; `return` em `void`.
- **Sinal:** `non-void function does not return a value in all control paths`; `incompatible pointer to integer conversion returning`.
- **Regra:** *"olha o tipo antes do nome da função: é isso que o `return` carrega. Tabela situação → `*param` → `return`."*

### Recursão: caso base e o `nb` que some
- **Erro:** faltou `if (power == 0) return 1` (só tinha `nb == 0 && power == 0`); `result * f(nb-1)` com `result = 1` (o `nb` atual não entra na conta).
- **Regra:** *"quantos passos pra trás a fórmula olha? Tantos casos base. E o valor atual (`n`) tem que aparecer na expressão: `n * f(n-1)`."* Exemplo `soma(n)`/`produto(n)`.

### Ponteiro duplo
- **Erro:** `&&argv`, `**argv` na chamada, `*strs[i]` sem parênteses, `arr = NULL` numa local achando que muda o caller.
- **Regra:** *"conta os `*` do tipo e vê quantos `[]` já usou. `(*range)[i]` com parênteses. Pra mudar a variável de quem chamou, escreva em `*param`."*

### malloc
- **Erro:** `char memory;` pra receber malloc; `free(memory)` depois do `return` dentro do `strdup`; `strlen(endstr)` logo depois do `malloc` (lixo); `malloc(n)` pra `int` sem `sizeof(int)`; `size == 0` sem `return` (cai e vaza).
- **Regra:** *"quem faz `malloc` entrega a posse; quem recebe dá `free`. Depois do `malloc`: checa `NULL`, inicializa, só então usa."*

### Coisas de C que não existem em JS
- `;` obrigatório (não tem ASI). `retutrn`/`;` faltando custam uma compilação — compilar cedo.
- `int i;` sem valor = lixo. `(void)argc;` pra parâmetro não usado com `-Werror`.
- `if (a = b)` atribui. `==` compara.
- Sem `.length`: `argc`, `size`, `strlen`.
- `'a'` é um número (97). `"a"` é um endereço de 2 bytes (`a`, `\0`).

### Patch em vez de reescrever
- **Erro:** quando o problema é de leitura do enunciado (não de sintaxe) — ex: `ft_range`, malloc contando elementos errado e caso decrescente não coberto — ele vai remendando o código aos poucos em vez de apagar e reescrever com a leitura correta. Gastou 5 tentativas num exercício que ele mesmo disse que sairia de primeira se tivesse reescrito.
- **Sinal:** grademe KO repetido no mesmo exercício, e cada tentativa nova só ajusta um pedaço pequeno do que já estava lá, sem revisitar o enunciado inteiro.
- **Regra (dele mesmo):** *"erro de não ter lido o enunciado direito = apaga e reescreve do zero, não remenda."* Se ele estiver remendando por 2+ tentativas seguidas num erro que já vem do enunciado, perguntar se não é hora de apagar e recomeçar.

### Entrega (git) — o que já quase custou um módulo
- **Erro:** `main` de teste descomentado na versão commitada (o disco tinha `/* */`, o remoto não) → `main` duplicado → KO no ex01 → zera o resto por ordem. Pasta arrastada por engano (`ex06/ex07/ft_strupcase.c`) → arquivo inesperado no ex06.
- **Sinal:** `git status` com `M`, `git ls-tree -r origin/master` com caminho estranho.
- **Regra:** *"norminette e mini olham o disco; a moulinette olha o remoto. Antes de marcar avaliação: status vazio, nada pendente de push, `ls-tree` só com `exNN/*.c`."*

## Checklist "antes de dizer terminei" (cobre dele, um por um)

1. Compila com `cc -Wall -Wextra -Werror`? (zero warnings)
2. Rodei com o **menor** caso? (`0`, `""`, `size 0`, lista vazia, 1 elemento)
3. Rodei com **negativo** e com `INT_MIN`/`INT_MAX` se há conta?
4. Rodei com o caso **do exemplo do enunciado** e comparei com `cat -e`? (o `$` mostra o `\n`)
5. Cada frase do enunciado com "se / quando / deve retornar" virou um `if` ou um teste?
6. Todo `malloc` tem `if (== NULL)`, inicialização, e `free` do lado de quem chamou?
7. Todo `while` tem o `++` e a condição na unidade certa?
8. Tabela de retorno: cada caminho da função chega num `return` do tipo certo?
9. Nome do arquivo e da função **exatamente** como o enunciado (sem espaço no nome, pasta `exNN`)?
10. Norminette (fora do exame) — só depois de tudo acima.

## Padrões de leitura de enunciado

- "incluído / excluído" → borda do loop (`<` vs `<=`).
- "retorna 0 se X" + "retorna -1 se Y" → tabela de contrato; os dois canais (`*param` e `return`) preenchidos em cada caso.
- "não deve gerir overflow" → não trate; mas também não crie um (`i * i` na sqrt).
- "seguido de uma quebra de linha" → `write(1, "\n", 1)` depois do loop, e `cat -e` pra conferir.
- "string elegível pra `free()`" → veio de `malloc`; nunca literal, nunca `NULL`.
- "não serão necessariamente editáveis" → não modifique o parâmetro; copie.
- "cabe num int" → pode usar `int`, mas INT_MIN ainda existe.
- "se o número de argumentos não for 1, mostra `\n`" (exame) → primeiro `if` do `main`.
