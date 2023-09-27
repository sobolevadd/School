
def my_function_2(k:Karel)->Karel:
    """Položí značky na všechna sousední pole."""
    k.hide()

    k.step()
    k.put()

    k.turn_left()
    k.step()
    k.put()

    k.turn_left()
    k.step()
    k.put()

    k.step()
    k.put()

    k.turn_left()
    k.step()
    k.put()

    k.step()
    k.put()

    k.turn_left()
    k.step()
    k.put()

    k.step()
    k.put()


    k.turn_left()
    k.step()
    k.turn_left()
    k.step()
    k.turn_left()
    k.turn_left()

    k.unhide()
    return k


 def my_function_2(k:Karel)-> Karel:
    '''S využitím možnosti skrytí pomocných činností vytvoří se zadaným robotem,
    pokud je to možné, ze značek symbol ve tvaru písmene "H" a vrátí odkaz na
    svůj argument, který bude posunut o jedno pole dopředu'''
    hide(k)
    put(k);put(k);put(k);put(k);put(k);put(k);put(k);put(k);put(k);put(k)
    step_back(k) #135
    put(k);put(k);put(k);put(k);put(k);put(k);put(k);put(k);put(k);put(k)
    step_back(k)
    put(k);put(k);put(k);put(k);put(k);put(k);put(k);put(k);put(k);put(k)
    turn_left(k) #136
    step_back(k)
    turn_left(k)
    step_back(k)
    put(k);put(k);put(k);put(k);put(k);put(k);put(k);put(k);put(k);put(k)
    turn_left(k)    #138
    step(k)
    put(k);put(k);put(k);put(k);put(k);put(k);put(k);put(k);put(k);put(k)
    turn_left(k)    #139
    step_back(k)
    put(k);put(k);put(k);put(k);put(k);put(k);put(k);put(k);put(k);put(k)
    step(k)         #140
    step(k)
    put(k);put(k);put(k);put(k);put(k);put(k);put(k);put(k);put(k);put(k)
    turn_left(k)    #141
    step(k)
    step(k)
    turn_left(k)
    turn_left(k)
    turn_left(k)
    step(k)         #142
    unhide(k)
    return k
