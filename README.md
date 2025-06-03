
# Super Trunfo - Comparação de Cartas

Projeto em linguagem C para cadastro e comparação interativa de cartas representando cidades ou países, com base em atributos como população, área, PIB, densidade demográfica e mais.

## 📋 Funcionalidades

- Cadastro de duas cartas com os seguintes dados:
  - Estado
  - Código da carta
  - Nome da cidade
  - População
  - Área (em km²)
  - PIB (em bilhões de reais)
  - Pontos turísticos

- Cálculo automático de:
  - Densidade populacional (hab/km²)
  - PIB per capita (reais)

- **Menu interativo com `switch-case`** para o usuário escolher qual atributo comparar:
  - 1 - População
  - 2 - Área
  - 3 - PIB
  - 4 - Pontos Turísticos
  - 5 - Densidade Demográfica (menor valor vence)
  - 6 - PIB per Capita

- **Lógica de comparação com `if-else`** exibindo o vencedor ou empate.

---

## 🧪 Exemplo de Execução

```
== Cadastro da Carta 1 ==
Estado: SP
Código: A01
Nome da cidade: São Paulo
População: 12300000
Área (km²): 1521.11
PIB (em bilhões): 699.28
Pontos turísticos: 45

== Cadastro da Carta 2 ==
Estado: RJ
Código: B02
Nome da cidade: Rio de Janeiro
População: 6748000
Área (km²): 1200.25
PIB (em bilhões): 300.5
Pontos turísticos: 30

===== MENU DE COMPARAÇÃO =====
1 - População
2 - Área
3 - PIB
4 - Pontos Turísticos
5 - Densidade Demográfica
6 - PIB per Capita
Escolha uma opção: 6

Comparando São Paulo (SP) x Rio de Janeiro (RJ)
PIB per Capita:
São Paulo: 56860.98 | Rio de Janeiro: 44528.84
Resultado: São Paulo venceu!
```

---

## ▶️ Como compilar e executar

1. Compile o código:
   ```bash
   gcc super_trunfo.c -o super_trunfo
   ```

2. Execute o programa:
   ```bash
   ./super_trunfo
   ```

---

## 📁 Estrutura do Projeto

```
super_trunfo.c     → Código-fonte principal
README.md          → Instruções de uso e documentação
```

---

## 🧠 Conceitos utilizados

- Entrada de dados com `scanf` e `fgets`
- Cálculo de indicadores
- Estruturas de decisão: `if`, `else`, `switch`
- Lógica condicional e validação de entrada
