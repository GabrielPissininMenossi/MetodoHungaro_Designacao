
# Método Húngaro

É um método utilizado para designações de tarefas ou outras atividades para pessoas ou outras atribuições.
Se fosse utilizado o método convencional para a combinação de possibilidades seria necessário uma execução fatorial, do tipo !n. Mas com esse método a complexidade geral do algoritmo fica em torno de uma complexidade cúbica, algo como: n³.
## Conhecimentos

 - [Alocação Ótima](https://www.google.com/url?sa=t&source=web&rct=j&url=https%3A%2F%2Fproceedings.sbmac.org.br%2Fsbmac%2Farticle%2Fdownload%2F2694%2F2716%2F5400%23%3A~%3Atext%3DO%2520M%25C3%25A9todo%2520H%25C3%25BAngaro%2520%25C3%25A9%2520um%2520algoritmo%2520que%2C%2Cquadradas%2520cujas%2520entradas%2520s%25CB%259Cao%2520n%25C3%25BAmeros%2520inteiros%2520positivos.&ved=0CAEQ1fkOahcKEwjQ5c_VnP6QAxUAAAAAHQAAAAAQAg&opi=89978449)
 - [Artigo explicativo](https://www.scribd.com/document/184694528/Metodo-Hungaro#:~:text=M%C3%A9todo%20H%C3%BAngaro%20*%20O%20documento%20apresenta%20o,Obra%203%2C%20com%20custo%20total%20de%20R$)
 - [Pseudocódigo](https://elemarjr.com/clube-de-estudos/artigos/o-algoritmo-hungaro-e-a-solucao-de-problemas-de-atribuicao/)


## Execute Localmente

🧰 Instalação da Biblioteca Conio2 (Windows)

A interface gráfica deste projeto utiliza funções da biblioteca Conio2, que não faz parte do padrão C.
Siga atentamente os passos abaixo para instalar e configurar corretamente no Dev-C++.

🔹 1. Baixar os arquivos necessários
- Biblioteca Conio2 (arquivo .DevPak): [Baixar Conio2](https://sourceforge.net/projects/conio/files/devpak/CONIO%202.0/conio-2.0-1mol.DevPak/download)
- Dev-C++ (versão recomendada 5.11): [Baixar Dev-C++](https://sourceforge.net/projects/orwelldevcpp/)
Recomenda-se instalar o Dev-C++ na pasta: C:\DEVcpp

🔹 2. Instalar o Dev-C++
- Execute o instalador do Dev-C++ normalmente.
- Altere o diretório de instalação para:
    ```bash
    C:\DEVcpp
    ```
- Abra o programa após instalar

🔹 3. Instalar o Conio2 pelo Package Manager
- No Dev-C++, acesse o menu:
    
    Ferramentas → Package Manager
- Clique no botão Install.
- Localize o arquivo conio-2.0-1mol.DevPak que você baixou.
- Conclua a instalação.
- Verifique se o pacote CONIO aparece na lista do Package Manager.
Caso não apareça:
➤ Dê dois cliques no arquivo .DevPak para instalar novamente.

🔹 4. Configurar o compilador (Linker)
- Vá em: Ferramentas → Opções do Compilador
- Em Configurações para o compilador, selecione:
    - TDM-GCC 4.7.1 32-bit Release
    - (Repita depois para TDM-GCC 4.7.1 32-bit Debug)
- No campo:
    - "Adicionar estes comandos à linha de comando do linker", adicione:
        ```bash
        -lconio
        ```
    ⚠️ Não esqueça do espaço antes de -lconio

🔹 5. Copiar os arquivos necessários do Conio2

📁 5.1 Copiar o arquivo de cabeçalho
- Acesse:
    ```bash
    C:\DEVcpp\include
    ```
- Copie o arquivo:
    ```bash
    conio2.h
    ```
- Cole em:
    ```bash
    C:\DEVcpp\MinGW64\include
    ```
📁 5.2 Copiar as bibliotecas (.a)
- Vá até:
    ```bash
    C:\DEVcpp\lib
    ```
- Copie os seguintes arquivos (ou todo o conteúdo da pasta):
    - libconio.a
    - libconio.dll.a
- Cole em:
    ```bash
    C:\DEVcpp\MinGW64\x86_64-w64-mingw32\lib32
    ```

🔹 6. Testar se a instalação funcionou
- Crie um novo projeto no Dev-C++ e cole o código abaixo:
- Faça um teste do código (execute):
```c
#include <stdio.h>
#include <conio2.h>

int main() {
    textcolor(14);
    gotoxy(10, 10);
    cprintf("Teste Conio2 funcionando!");
    return 0;
}
```
✔ Se o texto aparecer na linha 10, coluna 10, a instalação está correta.

❌ Caso contrário, revise os passos acima com atenção.

Se tudo ocorreu corretamente, faça um clone do projeto e realize o teste.

## Exemplo de entrada e saída

Matriz de entrada, nesse caso de ordem 4 (4x4):
```txt
A B C D
2 1 4 2
3 4 1 6
1 2 6 5
1 3 3 7

```
Apenas precisa rodar, irá aparecer o resultado final no cmd:
```
--- FIM ---

### Resultado Final ###
    D1   D2   D3   D4
 P1 [2] [-1] [4] [0]
 P2 [2] [2] [0] [3]
 P3 [-1] [0] [5] [2]
 P4 [0] [1] [2] [4]
```
## Apêndice

Aplicação do algoritmo método húngaro, para achar a solução ótima de uma designação qualquer. 
Problema de Grafos, abordado na disciplina de Teoria dos Grafos, do sexto semestre do curso de Ciência da Computação da Unoeste (Universidade do Oeste Paulista) - FIPP (Faculdade de Informática de Presidente Prudente).
## Autores

- [Gabriel Pissinin Menossi - GabrielPissininMenossi](https://github.com/GabrielPissininMenossi)
- [Matheus Antonucci Mendonça - matheusmen1](https://github.com/matheusmen1)

