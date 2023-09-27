#Příliš žluťoučký kůň úpěl ďábelské ó - PŘÍLIŠ ŽLUŤOUČKÝ KŮŇ ÚPĚL ĎÁBELSKÉ Ó
#P:/p1_INP/game/tests/test_interface.py
"""
Sada tříd a funkcí pro otestování korektnosti definic továrních objektů.

Způsob testování je identifikován zadaným level.
Jeho hodnoty jsou následující:

v0A - Testuje se jenom tovární objekt a jím poskytnutá identifikace autora
v1A - Testuje se pouze šťastný scénář
v1B - Testuje se základní čtveřice scénářů
v1C - Navrhuje se základní architektura, testuje se jen vizuálně
      na přítomnost navržených objektů a jejich požadovaných metod
v1D - Testuje se, že se hra úspěšně odstartuje
v1E - Testuje se, že hra úspěšně vybuduje svůj svět
v1F - Testuje se, že hra úspěšně projde startovacím scénářem,
      který obsahuje pouze základní povinné akce
v1G - Testuje se, že hra úspěšně projde startovacím a chybovým scénářem
v1H - Testuje se, že hra úspěšně projde všemi čtyřmi základními scénáři,
      a je tak připravena k odevzdání

zXY - Testuje se úspěšné zapracování rozšíření na obhajobě,
      kd XY identifikuje jednotlivé zadání
"""
import dbg
dbg.start_mod(0, __name__)
############################################################################

import traceback

from datetime import datetime

from ..api.interfaces   import IPkgInitor
from ..api.scen_types   import (stHAPPY, stBASIC,
                                stMISTAKES, stMISTAKES_NS)
from  .                 import Level, Verbosity, prVb
from  .common           import to_ascii
from  .common.texts     import *


# from .common.errors     import clear_err_msgs, add_err_msg, get_err_msgs

# Budou-li se testovat scénáře
# from .test_scenario import test_scenarios_from

# Bude-li se testovat hra
# from .test_game import test_game_from



############################################################################

def ERROR(message:str):
    """Vypíše chybovou zprávu a vyhodí výjimku
    """
    from .common.texts import N_BEFORE_N, N_AFTER_N
    print(f'{N_BEFORE_N}{message}{N_AFTER_N}')
    raise Exception()



############################################################################

def pre_import():
    """Sada akcí, které se musí udělat před tím,
    než se importuje další testovaný modul.
    """
    from ..api.scenario import Scenario
    Scenario.count = 0


# @dbg.prSEd() #1, 3*(66*'T' + '\n'))
def test(portal:IPkgInitor, level:Level) -> bool:
    """Otestuje zadaný tovární objekt a jím poskytnuté objekty hry
    přičemž hloubku testování nastavuje argument level.
    Podle nastavené hloubky tetování postupně ověří, že:
    - Zadaná továrna poskytne podklady pro identifikaci autora
      a definuje metody pro získání klíčových objektů hry.
    - Scénáře jsou definované konzistentně.
    - Hru je možno odehrát podle definovaných scénářů.
    """
    global _portal
    _portal    = portal
    _start_time = f'{datetime.now()}'
    errors = False
    try:
        epilog = f'{_start_time} - Vyhořel při verifikací autora a balíčku'
        _verify_author()
        epilog = f'{_start_time} - Vyhořel při přebírání šťastného scénáře'
        n2s = portal.NAME_2_SCENARIO
        # dbg.prIN(1, f'{type(n2s) = }')
        if not isinstance(n2s, dict):
            n2s = n2s()
        happy_steps =n2s[stHAPPY.name].steps
        invitation  = happy_steps[0].message
        prolog = (f'Autor:   {_autor_both}\n'
                  f'Balíček: {portal.__package__}\n'
                  f'########## START: {_start_time}\n'
                  f'{HASH_N}{invitation}{N_DOUBLE}')
        epilog = (f'{HASH_N}'
                  f'########## KONEC testu autora {_autor_both}\n'
                  f'{HASH_N}')
        prVb(Verbosity.SUMMARY, prolog)
        if level >= Level.HAPPY:
            # Budou se testovat scénáře
            from .test_scenario import test_scenarios_from
            global result
            result = test_scenarios_from(portal, level)
            # dbg.prIN(1, 2*(66*'S' + '\n'))
        if level >= Level.START:
            # Bude se testovat také hra
            from .test_game import test_game_from
            test_game_from(portal, level)
            # dbg.prIN(1, 2*(66*'P' + '\n'))
    except Exception as ex:
        # dbg.prIN(1, 2 * (66 * 'E' + '\n'))
        result = f'Výjimka: {ex}'
        traceback.print_exc()
    finally:
        # dbg.prIN(1, 2 * (70 * 'F' + '\n'))
        msg = (result if isinstance(result, str)
                    else dbg.prSeq(result, False))
        print(f'{70*"Z"}\nZávěrečný souhrn:\n{msg}\n{epilog}')
        # if errors:
        #     print('Testovaný program vyhodil výjimku:')
        # else:
        #     print('Testovaný program prošel')
    return result



############################################################################

def _verify_author():
    """Ověří že testovaný tovární objekt umí dodat autora a jeho ID
    a že dodané stringy vyhovují požadavkům.
    """
    global _author_name, _author_ID, _author_lang, _autor_both
    full_name= _portal.__name__
    
    # pkg_name = full_name[len('game.'):]
    # if ((type(_portal) != type(dbg))       or
    #     (not full_name.startswith('game.')) or
    #     (full_name.find('.',  len('game.')) != -1)
    #    ):
    #     raise Exception(f'Tovární objekt «{full_name}»\n'
    #                     f'není řádným podbalíčkem balíčku game')
    pkg_name = (full_name[(full_name.rindex('.')+1):]
                if '.' in full_name else full_name)
    try:
        _author_name = _portal.AUTHOR_NAME
        _author_ID   = _portal.AUTHOR_ID
    except Exception:
        ERROR(f'Tovární objekt «{full_name}»\n'
              f'neposkytuje jméno a/nebo identifikační string autora')
    try:
        _author_lang = _portal.AUTHOR_NATIVE_NAME
    except Exception:
        _author_lang = _author_name+' - Nebylo zadáno jméno v rodném jazyce'
    if _author_ID != _author_ID.upper():
        ERROR('Identifikační string autora není velkými písmeny: '
             + _author_ID )
    _autor_both = _author_ID + ' - ' + _author_name
    name_parts  = _author_name.split(' ', 1)
    surname     = name_parts[0]
    if surname != surname.upper():
        ERROR(f'Příjmení autora není velkými písmeny: {_author_name}')
    forename = name_parts[1]
    names    = forename.split()
    for i in range(len(names)): # Každé křestní je třeba upravit zvlášť
        names[i] = names[i].capitalize()
    fnc = ' '.join(names)       # Vrácení do původního uspořádání
    if forename != fnc:
        ERROR (f'Křestní jméno neodpovídá: {_author_name=}\n'
               f'   {forename             = }\n'
               f'   {forename.capitalize()= }' )

    ascii_surname = to_ascii(surname)
    requested     = (_author_ID + '_' + ascii_surname).lower()
    # print(f'{ascii_surname=}, {requested=}, {pkg_name=}')
    if pkg_name != requested:
        ERROR (f'CHYBA: Název balíčku neodpovídá požadavkům\n' 
               f'       Požadováno: {requested!r}\n'
               f'       Obdrženo:   {pkg_name!r}'
               )



def _verify_package():
    """Zjistí, v jakém balíčku se tovární objekt nachází a ověří,
    že název balíčku je správně odvozen z ID a jména autora.
    """
    return
    # TODO Dodělat test korektnosti názvu balíčku
    global _package
    # Objekt musí být buď modul, nebo instancí třídy definované v modulu
    if _portal.__class__.__name__ == 'portal':
        _package = _portal.__class__.__package__
    else:
        _package = _portal.__class__.__module__.__package__



############################################################################

_H60: str = 60 * '#'
_E60: str = 60 * '='

_portal:IPkgInitor     # Odkaz na testovaný tovární objekt
_author_name:str        # Jméno autora
_author_ID:str          # Identifikační string autora
_autor_both:str         # level autora následované jeho jménem
_package:str            # Název balíčku, v němž je tovární třída
_start_time:datetime    # Čas spuštění testu


############################################################################
dbg.stop_mod(0, __name__)
