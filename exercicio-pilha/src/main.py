def verificar_balanceamento(expressao):
    pilha = []
    pares = {')': '(', ']': '[', '}': '{'}
    for caractere in expressao:
        if caractere in "({[":
            pilha.append(caractere)
        elif caractere in ")}]":
            if not pilha or pilha[-1] != pares[caractere]:
                return False
            pilha.pop()
    return not pilha

# Testando o programa
expressoes = [
"(a + b)",
"{[a * (b + c)]}",
"a + {b - [c * d]}",
"a + (b",
"{[a * b]",
"(a + b)}",
"a + {b - [c * d}"
]
for exp in expressoes:
    print(f"Expressão: {exp}")
    print("Balanceada" if verificar_balanceamento(exp) else "Não Balanceada")

    print("-" * 30)