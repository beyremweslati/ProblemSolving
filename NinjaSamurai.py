Position = {'high': 'h', 'low': 'l'}  #don't change this!

class Warrior():
    def __init__(self,name):
        # each warrior should be created with a name and 100 health points
        self.name = name
        self.health = 100
        # default guard is "", that is unguarded
        self.block = ""
        self.deceased = False
        
    def attack(self, enemy, position):
        damage = 0
        # attacking high deals 10 damage, low 5
        # 0 damage if the enemy blocks in the same position
        if enemy.block != position: damage += 10 if position == Position['high'] else 5
        # and even more damage if the enemy is not blocking at all
        if enemy.block == "": damage += 5
        set_health(enemy, enemy.health - damage)
    
def set_health(self, new_health):
    # health cannot have negative values
    self.health = max(0, new_health)
    # if a warrior is set to 0 health he is dead
    if self.health == 0:
        self.deceased = True
        self.zombie = False
    # he would be a zombie only if he was already dead
    if self.deceased: self.zombie = True

ninja = Warrior('Hanzo Hattori')
samurai = Warrior('Ryoma Sakamoto')
i = 1
while samurai.health > 0 and ninja.health > 0:
    print("Round", i , "Fight!")


    samurai.block = input("Samurai block? (h/l) : ")
    attS = input("Ninja attack? (h/l) :")
    ninja.attack(samurai, attS)
    


    ninja.block = input("Ninja block? (h/l) : ")
    attS = input("Samurai attack? (h/l) :")
    samurai.attack(ninja, attS)
    print("Round", i , "Ends!")
    print("--------------------")
    print("Ninja health : ", ninja.health,"|")
    print("Samurai health : ", samurai.health,"|")
    print("--------------------")
    i += 1