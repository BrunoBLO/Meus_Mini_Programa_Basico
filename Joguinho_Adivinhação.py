import random
from time import sleep
sorteio, i, vitoria, por = 0, 0, 0, 0
again = 1
lista = []
org, org2 = 80 * '-', 80 * '*'


def gera_segredo(valor_maximo):

    if valor_maximo <= 100:
        usuario = 7
    else:
        usuario = 10
    return usuario

def jogar(segredo, tentativas):
    i, adivinha = 0, 0

    '''teste de codigo: Aqui testei se o codigo tava funcionando
    print('Segredo: ', segredo)
    print(org)
    '''

    while i < tentativas:
        print('Você tem {} tentativas'.format(tentativas - i))
        adivinha = int(input("Adivinhe que numero sorteio: "))

        if adivinha < segredo:
            print('MAIOR')
            print(org)
        if adivinha > segredo:
            print('MENOR')
            print(org)


        if adivinha == segredo: break

        i += 1

    return adivinha, i

# def-----------------------------------------------------------------------------------

while again == 1:
    print(org2)
    numero = int(input('Quer adivinhar um número com valor máximo 100 ou 1000: '))

    usuario = gera_segredo(valor_maximo = numero) #def 1

    print(org2)
    print('Novo jogo. O número secreto estará entre 0 e', numero) #ate que numero aleatoriza
    print(org2)

    sorteio = random.randint(0,numero)#aleatorio


    limite, i = jogar(segredo=sorteio, tentativas=usuario) #jogo

    lista.append(i)

#erro----------------------------
    if limite == sorteio:
        print(org2)
        print(org2)
        print('Parabéns, você acertou! Foram utilizadas {} tentativas' .format(i+1))
        print(org2)
        vitoria += 1
    else:
        print(org2)
        print('Você perdeu! Tente novamente')
        print('O Numero sorteiado foi:', sorteio)

    again = int(input('Aperte "1" para jogar novamente: '))
    print(org2)
    por += 1


#print(lista) #teste da lista


if por >= 3:
    porcento = (vitoria / por) * 100
    print(org)
    print('O SEU PERCENTUAL DE VITÓRIA É DE {:.1f}%'.format(porcento))
    print(org)

tamanho = int(len(lista))
i = 0

#Extra
print(org2)
print('Resumo de Partidas:')
while i < tamanho:
    print('Na {}° rodada você tentou {} vez(es)' .format(i + 1,lista[i]))
    i += 1
print(org)

print('Fim de Programa')
sleep(60)
print('O Programa vai ser finalizado...')
sleep(5)


