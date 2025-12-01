from compactacao import compactar_dna, descompactar_dna
input_txt = 'compactacao/dna/dna.txt'
output_bin = 'compactacao/dna/compactado.bin'

compactar_dna(input_txt, output_bin)
descompactar_dna(output_bin, 'compactacao/dna/dna_descompactado.txt')
