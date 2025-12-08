def compactar_dna(input_txt, output_bin):
    mapping = {
        'A':'00', 'C':'01', 'G':'10', 'T':'11'
    }

    
    with open(input_txt, 'r') as f:
        dna = f.read().strip().replace("\n", "").upper()

    bitstring = ''.join(mapping[ch] for ch in dna)

    while len(bitstring) % 8 != 0:
        bitstring += '0'

    compressed_bytes = int(bitstring, 2).to_bytes(len(bitstring) // 8, byteorder='big')

    with open(output_bin, 'wb') as f:
        f.write(compressed_bytes)

    print("Compactação concluída!")


def descompactar_dna(input_bin, output_txt):
    reverse_mapping = {
        '00': 'A',
        '01': 'C',
        '10': 'G',
        '11': 'T'
    }

    
    with open(input_bin, 'rb') as f:
        compressed_bytes = f.read()

    bitstring = bin(int.from_bytes(compressed_bytes, byteorder='big'))[2:]

    bitstring = bitstring.zfill(len(compressed_bytes) * 8)

    dna = ''.join(reverse_mapping[bitstring[i:i+2]] for i in range(0, len(bitstring), 2))

    with open(output_txt, 'w') as f:
        f.write(dna)

    print("Descompactação concluída!")

if __name__ == "__main__":
    input_txt = 'dna/dna.txt'
    output_bin = 'dna/compactado.txt'

    compactar_dna(input_txt, output_bin)
    descompactar_dna(output_bin, 'dna/dna_descompactado.txt')
