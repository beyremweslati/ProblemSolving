def Get_Living_cells(cells,l,c):
    living = 0
    for i in range(l,l+3):
        for j in range(c,c+3):
            if cells[i][j] == 1:
                living += 1
    return living

def next_gen(cells):
    InitialLineSize = len(cells)
    InitialColumnSize = len(cells[0])
    FinalCells = [[] for i in range(InitialLineSize)]

    RightLineSize = InitialLineSize + 2
    RightColumnSize = InitialColumnSize + 2
        
    RightCells = list(cells)
    RightCells.insert(0,[])
    RightCells.insert(RightLineSize,[])
    for i in range(1,InitialLineSize+1):
        RightCells[i].insert(0,0)
        RightCells[i].insert(RightColumnSize,0)
    for i in range(0,RightColumnSize):
        RightCells[0].append(0)
        RightCells[RightLineSize-1].append(0)

    for i in range(1,InitialLineSize+1):
        for j in range(1,InitialColumnSize+1):
            if RightCells[i][j] == 1:
                Live = True
            else:
                Live = False
            tempL = i - 1
            tempC = j - 1
            LivingCells = Get_Living_cells(RightCells,tempL,tempC)
            DeadCells = 8 - LivingCells
            if Live:
                LivingCells -= 1
                if LivingCells < 2 or LivingCells > 3:
                    FinalCells[i-1].append(0)
                else:
                    FinalCells[i-1].append(1)
            else:                    
                if LivingCells == 3:
                    FinalCells[i-1].append(1)
                else:
                    FinalCells[i-1].append(0)
    return FinalCells