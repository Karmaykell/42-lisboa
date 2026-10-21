# 42 Lisboa

Repositorio unico de estudo da 42 Lisboa, sincronizado entre o PC (Linux) e o Mac.

## Estrutura

| pasta | conteudo |
|---|---|
| `piscine/` | Piscine C: `shell00`, `shell01`, `C00` a `C09`, `rush`, `accept_lisboa` |
| `piscine-reloaded/` | Piscine Reloaded `ex00` a `ex27` (100% na moulinette) |
| `exam-prep/` | exercicios de simulado de exame |
| `common-core/milestone-1/libft/` | projeto libft (em andamento) |
| `subjects/` | PDFs dos enunciados |
| `tools/` | apoio para testes locais, ex.: `putchar.c` |

## Nomes antigos

`C piscine shell 00 fixed 2st` -> `piscine/shell00`, `C piscine shell 01 fixed` -> `piscine/shell01`,
`C08_push` -> `piscine/C08`.

## Trabalhar nos dois computadores

    git pull      # antes de comecar
    git add -A && git commit -m "..." && git push

## Entregar na vogsphere

A vogsphere trava o repo depois da correcao, e cada tentativa tem um repo novo.
Clone o repo da intra numa pasta separada, copie so o que o subject pede e faca o push de la.
Nao ponha `.git` da vogsphere dentro deste repo.

## Fora do repo

- `42-piscine-exam-trainer`: https://github.com/tomascoutotech/42-piscine-exam-trainer
  (codigo de terceiros; clone a parte se precisar).
