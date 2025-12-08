import gzip
def compactar_gzip():
    with open('/home/talvan/Diretorios/EDL/compactacao/compactacao_gzip/dna.txt', 'rb') as dna_original:
        with gzip.open('/home/talvan/Diretorios/EDL/compactacao/compactacao_gzip/dna_compactado.txt', 'wb') as dna_comprimido:
            dna_comprimido.write(dna_original.read())
            print("Arquivo compactado!")

def descompactar_gzip():
    with gzip.open('/home/talvan/Diretorios/EDL/compactacao/compactacao_gzip/dna_compactado.txt', 'rb') as dna_comprimido:
        arquivo = dna_comprimido.read()

    with open('/home/talvan/Diretorios/EDL/compactacao/compactacao_gzip/dna_descompactado.txt', 'wb') as dna_descomprimido:
            dna_descomprimido.write(arquivo)
            print("Arquivo descompactado!")



if __name__ == "__main__":
    compactar_gzip()
    descompactar_gzip()

