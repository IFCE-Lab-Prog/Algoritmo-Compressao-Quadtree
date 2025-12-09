# Compressor de Imagem Quadtree

Este projeto implementa um sistema de compressão e descompressão de imagens digitais utilizando a estrutura de dados **Quadtree**. O algoritmo foca na compressão do formato **PGM (Portable Gray Map)**, agrupando regiões homogêneas da imagem para reduzir o tamanho do arquivo final.

## Requisitos da Imagem

Para garantir o funcionamento correto do algoritmo, a imagem de entrada deve obedecer rigorosamente às seguintes restrições:

1.  **Formato:** Deve ser **PGM P5** (Binário). O formato P2 (ASCII) não é suportado.
2.  **Geometria:** A imagem deve ser estritamente **Quadrada** (Largura = Altura).
3.  **Dimensões:** As dimensões devem ser uma **Potência de 2** (ex: 256 x 256, 512 x 512, 1024 x 1024, etc.).

## Compilação

O projeto está configurado para ser compilado facilmente tanto em ambientes Linux (via Makefile) quanto em Windows (via Scripts em Lote). Certifique-se de ter o compilador `gcc` instalado e configurado no PATH do seu sistema.

### Linux (Via Makefile)

Abra o terminal na pasta raiz do projeto e execute:

```bash
# Compilar (Gera encoder.e e decoder.e)
make

# Limpar arquivos gerados pela compilação
make clean

```

Após a compilação, execute o encoder.e da seguinte forma:

./encoder.e <imagemDeEntrada.pgm> <bitstreamDeSaída.bin>

Após gerar o .bin, execute o decoder.e da seguinte forma:

./decoder.e <bitstream.bin> <imagemReconstruída.pgm>

### Windows (Via Script)

Abra o terminal na pasta raiz do projeto e execute:

```bash
# Compilar (Gera encoder.e e decoder.e)
.\compile.bat

# Limpar arquivos gerados pela compilação
.\clean.bat

```

Ou simplesmente dê dois cliques no arquivo .bat para executá-lo.

Após a compilação, execute o encoder.e da seguinte forma:

.\encoder.exe <imagemDeEntrada.pgm> <bitstreamDeSaida.bin>

Após gerar o .bin, execute o decoder.e da seguinte forma:

.\decoder.exe <bitstream.bin> <imagemReconstruida.pgm>
