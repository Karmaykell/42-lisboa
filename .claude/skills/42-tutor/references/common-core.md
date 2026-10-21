# Common core — como o método escala

O princípio não muda: **ele escreve, você guia**. O que muda é que os projetos têm 500–5000 linhas, várias semanas, avaliação por pares com defesa oral, e norma obrigatória. Você passa a ajudar em **design, testes e ferramentas**; a lógica continua dele.

## O que você pode escrever no common core (e o que não)

Pode:
- **Testes**: `main`s de teste, scripts que comparam a saída dele com a do programa real (`diff <(./ft_printf ...) <(printf ...)`), geradores de casos aleatórios, casos de borda.
- **Ferramentas**: Makefile de exemplo (ele adapta), `.gitignore`, comandos de `valgrind`, scripts de build/run.
- **Exemplos isolados de API**: como `read` retorna, como `fork`+`pipe`+`dup2` se encadeiam, como `mlx_pixel_put` funciona, `readline` — num arquivo de brinquedo, não no projeto.
- **Diagramas**: fluxo do parser, máquina de estados, estrutura de dados, quem é dono de qual `malloc`.
- **Revisão**: ler o código dele e apontar bugs, leaks, casos não tratados, norma — como um avaliador faria.

Não pode:
- A lógica do projeto: o parser do minishell, o algoritmo do push_swap, o raycasting do cub3d, o `get_next_line` em si.
- "Reestruturar" o código dele por conta própria. Sugere; ele decide e faz.

## Rotina de verificação (versão common core)

1. `make -n` / `make` sem warnings, `make re` funciona, `make fclean` limpa tudo, **não relinka** (`make` duas vezes → "nothing to be done").
2. `norminette` em todos os `.c` e `.h`.
3. Testes dele + os seus. Com **`valgrind --leak-check=full --show-leak-kinds=all --track-fds=yes`** (ou `-fsanitize=address,undefined` quando valgrind não roda).
4. Casos que o avaliador tenta: entrada vazia, gigante, inválida, `Ctrl+C`/`Ctrl+D`, arquivo inexistente, permissões.
5. Defesa: pede pra ele **explicar** uma função aleatória em voz alta. Se não conseguir, não está pronto.

## Projetos (ordem típica, círculos 0–6) e o que cada um cobra

### Círculo 0 — libft
- Reescreve a libc: `ft_strlen`, `ft_split`, `ft_strjoin`, `ft_atoi`, `ft_calloc`, `ft_strdup`, `ft_substr`, `ft_itoa`, `ft_strlcpy/lcat`, `ft_memcpy/move/set`, `ft_toupper`... e bônus de lista (`ft_lstnew`, `ft_lstadd_back`, `ft_lstmap`...).
- Ponte: **é a piscine inteira**, agora com `size_t`, `const`, e a semântica exata do `man`. Cada função deve bater com a original em todos os casos — teste com `diff` contra a libc.
- Armadilhas: `ft_split` com string vazia/só separadores; `ft_substr` com `start > len`; `ft_strlcat` com `size` pequeno; `ft_calloc` overflow; `ft_lstmap` liberando em falha de `malloc`.
- Método: um exercício da piscine por função — você conhece todos.

### Círculo 1 — get_next_line, ft_printf, Born2beRoot
- **get_next_line**: `read` com `BUFFER_SIZE` arbitrário (teste com 1, 42, 10000000), variável `static` que guarda o resto entre chamadas, uma linha por chamada incluindo `\n`, `NULL` no fim/erro, sem leaks. Bônus: vários fds ao mesmo tempo.
  Conceito novo: `static` local, `read` retornando 0/-1, buffer que atravessa chamadas.
- **ft_printf**: `va_list`, `va_arg`; conversões `%c %s %p %d %i %u %x %X %%`; retorna o número de chars escritos. Bônus: flags `-0.# +` e largura.
  Conceito novo: funções variádicas; tabela de dispatch (ponteiros de função, C11).
- **Born2beRoot**: VM, Debian/Rocky, particionamento LVM, `sudo`, `ssh` em porta 4242, UFW, política de senhas, script de monitoramento com `cron`. Sem código C — é sysadmin. Defesa oral pesada.

### Círculo 2 — push_swap, minitalk/pipex, so_long/fdf/fract-ol
- **push_swap**: duas pilhas, operações `sa pb rra...`, ordenar com o mínimo de movimentos (benchmarks: 100 números < 700, 500 < 5500). Parsing rigoroso (duplicatas, overflow, não-número → `Error`). Algoritmos: radix (fácil, passa), "turk"/chunks (melhor). Bônus: `checker`.
  Conceito novo: pensar em algoritmo e custo; listas encadeadas de verdade.
- **minitalk**: sinais `SIGUSR1/SIGUSR2`, `kill`, `sigaction`, transmitir uma string bit a bit entre dois processos. Bônus: acknowledge e unicode.
- **pipex**: `./pipex infile cmd1 cmd2 outfile` = `< infile cmd1 | cmd2 > outfile`. `fork`, `pipe`, `dup2`, `execve`, `access` no `PATH`. Bônus: múltiplos pipes e `here_doc`.
  Conceito novo: processos, descritores, quem fecha o quê.
- **so_long** (2D, mlx), **fdf** (wireframe 3D, projeção isométrica), **fract-ol** (Mandelbrot/Julia, zoom): MiniLibX, eventos, imagem em buffer. Parsing de mapa/argumentos rigoroso.

### Círculo 3 — philosophers, minishell
- **philosophers**: threads (`pthread_create/join`), mutexes, data races, deadlock, timing com `gettimeofday`/`usleep`. Um morto = fim; monitor. Bônus com processos e semáforos.
  Conceito novo: concorrência. Ferramentas: `-fsanitize=thread`, `valgrind --tool=helgrind`.
- **minishell** (em dupla): `readline`, prompt, `echo cd pwd export unset env exit` builtins, redireções `< > >> <<`, pipes, `$VAR`, `$?`, aspas simples/duplas, sinais `Ctrl+C/D/\`. Parser → tokens → AST/lista de comandos → executor com `fork/execve`.
  Conceito novo: projeto grande com design real; parsing sério; gestão de fds/processos; trabalhar em dupla com git.
  Método: **desenhar o pipeline antes de codar** (lexer → parser → expander → executor), decidir a estrutura de dados, dividir tarefas. Você ajuda a desenhar e a testar (compare com bash); a implementação é deles.

### Círculo 4 — cub3d/miniRT, NetPractice, CPP 00–04
- **cub3d**: raycasting estilo Wolfenstein, texturas, parsing do `.cub`. **miniRT**: ray tracing (esferas, planos, cilindros, luzes, sombras). Muita matemática vetorial — você pode explicar a matemática e desenhar; a implementação é dele.
- **NetPractice**: sub-redes, máscaras, roteamento — sem código; exercícios interativos.
- **CPP 00–04**: C++ básico: classes, `new/delete`, referências, `const`, forma canônica ortodoxa (construtor de cópia, operador `=`, destrutor), herança, polimorfismo, virtual, abstract, interfaces. Norma diferente (C++98). Conceito novo: orientação a objetos — analogias com classes de JS funcionam bem aqui.

### Círculo 5 — CPP 05–09, Inception, ft_irc/webserv
- **CPP 05–09**: exceções, templates, STL (`vector`, `map`, `stack`, iteradores, algoritmos), casts, `ex09` de algoritmo (bitcoin exchange, RPN, PmergeMe/Ford-Johnson).
- **Inception**: Docker, docker-compose, NGINX + WordPress + MariaDB em containers, volumes, secrets, TLS. Sem código C.
- **webserv** (HTTP server em C++98, `poll/epoll`, CGI, config estilo nginx) ou **ft_irc** (servidor IRC, sockets, `select/poll`, comandos do protocolo). Conceito novo: rede, I/O não-bloqueante, protocolo.

### Círculo 6 — ft_transcendence
- Web app full-stack (Pong online, autenticação, chat, torneios) — aqui o JS dele volta a valer. Módulos escolhíveis (backend framework, DB, 2FA, WebSocket, Docker).

## Hábitos a instalar desde a libft

- **git**: commits pequenos com mensagem que diz o porquê; branch por feature quando em dupla; nunca commitar `.o`, binários, `.DS_Store`.
- **Makefile** que não relinka, com `CFLAGS = -Wall -Wextra -Werror`, regras `all clean fclean re` e `bonus` quando houver.
- **valgrind** como reflexo: `valgrind --leak-check=full ./prog` antes de cada commit "funciona".
- **Teste automatizado próprio** (um `tests/` com script) — o avaliador vai tentar quebrar; ele deve ter tentado primeiro.
- **Ler o `man`** (`man 2 read`, `man 3 malloc`) antes de perguntar. Você ensina a ler a seção SYNOPSIS/RETURN VALUE/ERRORS.
- **Defesa oral**: ele explica; você faz as perguntas que um avaliador faria ("o que acontece se `read` retorna -1 no meio?", "onde esse `malloc` é liberado?", "por que `static` aqui?").

## Testers da comunidade (existem, use com cautela)

Como o mini-moulinette na piscine, há testers por projeto (francinette cobre libft/gnl/printf/minitalk/pipex/push_swap; `war-machine`, `libft-unit-test`, `gnlTester`, `printfTester`, `push_swap_tester`, `minishell_tester`, `42_minishell_tester`...). Rodam bordas e leaks. Não substituem entender o próprio código — mas evitam KO bobo na avaliação. Mesmo aviso do mini: não cobrem tudo.
