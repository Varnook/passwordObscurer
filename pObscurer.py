def obscurePassword(passwordUsuarie, passwordSize):    
    from hashlib import blake2b
    PYTHONHASHSEED = 0

    with open('/home/juan/Programs/passwordObscurer/hashlist.txt', 'r') as listaAux:
            hashList = listaAux.readlines()

    hashAux = blake2b(digest_size = 64)
    passwordHasheada = ''

    for i in range(2):
        hashAux.update(passwordUsuarie.encode())
        passwordHasheada += hashAux.hexdigest()

    passwordHasheada = str(int(passwordHasheada, 16))
    passwordNueva = ''
    iHashList = 0

    while len(passwordNueva) < passwordSize:
        posicionHashList = int(passwordHasheada[iHashList] + passwordHasheada[iHashList + 1])

        if posicionHashList > 90:
            posicionHashList -= 90

        passwordNueva += hashList[posicionHashList][0]
        iHashList += 2

    return passwordNueva
