import lzma

def compactar_dna_lzma(input_txt, output_bin):
    with open(input_txt, "r") as f:
        dna = f.read().replace("\n", "").encode()

    compressed = lzma.compress(dna)

    with open(output_bin, "wb") as f:
        f.write(compressed)

def descompactar_dna_lzma(input_bin, output_txt):
    with open(input_bin, "rb") as f:
        compressed = f.read()

    dna = lzma.decompress(compressed).decode()

    with open(output_txt, "w") as f:
        f.write(dna)


if __name__ == "__main__":
    input_txt = 'lzma/dna/dna.txt'
    output_bin = 'lzma/dna/dna.txt'

    compactar_dna_lzma(input_txt, output_bin)
    descompactar_dna_lzma(output_bin, 'lzma/dna/dna_descompactado.txt')
