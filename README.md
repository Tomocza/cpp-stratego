# cpp-stratego

## Diagrams ##

### Flowcharts ###

#### Top level game process ####
```mermaid

flowchart LR
START(("Start"))
playerConfig["Process player 
              config options"]
boardSetup["Players set 
            their boards up"]
isDraw{"Is the game 
        a draw?"}
isPlayerWin{"Is the current
            player winning?"}
playerActs["Current player acts"]
playerSwitch["Current player
              switches"]
END0((("Exit with winner")))
END1((("Exit with draw")))

START --> playerConfig
playerConfig --> boardSetup
boardSetup --> playerActs
playerActs --> isDraw
isDraw -- NO --> isPlayerWin
isDraw -- YES -----> END1
isPlayerWin -- NO --> playerSwitch
isPlayerWin -- YES ----> END0
playerSwitch --> playerActs

```

#### Board setup ####
```mermaid

flowchart LR
START(("Start"))
END0((("Exit")))
genPieces["Generate pieces 
          in inventory"]
selectPiece["Player selects
            a piece"]
choosePos["Player chooses 
           a position for the piece"]
isValidPos{"Is the chosen 
            position valid?"}
placePiece["Piece gets placed"]
isInvEmpty{"Are there any 
            pieces left?"}

START --> genPieces
genPieces --> isInvEmpty
isInvEmpty -- NO --> selectPiece
isInvEmpty -- YES --> END0
selectPiece --> choosePos
choosePos --> isValidPos
isValidPos -- NO --> choosePos
isValidPos -- YES --> placePiece
placePiece --> isInvEmpty


```

#### Is the chosen position valid? ####
```mermaid

flowchart LR
START(("Start"))
EXIT0((("Exit NO")))
EXIT1((("Exit YES")))
isOwnSide{"Is the position 
          on the player's side?"}
isPosEmpty{"Is the position empty?"}
isOnBoard{"Does the position 
           exist on the board?"}

START --> isOnBoard
isOnBoard -- YES --> isOwnSide
isOnBoard -- NO --> EXIT0
isOwnSide -- YES --> isPosEmpty
isOwnSide -- NO --> EXIT0
isPosEmpty -- YES --> EXIT1
isPosEmpty -- NO --> EXIT0

```

#### Battle (attacker perspective) ####
```mermaid

flowchart LR
START(("Start"))
EXIT0((("Exit with loss")))
EXIT1((("Exit with win")))
EXIT2((("Exit with draw")))
isRankEqual{"Are the ranks equal?"}
isRankHigher{"Is the attacker 
              ranked higher?"}
isDefBomb{"Is the defender 
            a bomb?"}
isAtkMiner{"Is the attacker 
            a miner?"}
isMarshalSpy{"Is the defender 
              a marshal and the 
              attacker a spy?"}

START --> isDefBomb
isDefBomb -- YES --> isAtkMiner
isAtkMiner -- NO ---> EXIT0
isAtkMiner -- YES --> EXIT1
isDefBomb -- NO --> isMarshalSpy
isMarshalSpy -- YES --> EXIT1
isMarshalSpy -- NO --> isRankEqual
isRankEqual -- YES --> EXIT2
isRankEqual -- NO --> isRankHigher
isRankHigher -- YES ---> EXIT1
isRankHigher -- NO ----> EXIT0

```

#### Current player act ####
```mermaid
flowchart LR
START((Start))
END((Exit))

clickTile[Player cliks on a tile]
isPlayersPieceOnTile{Is player's piece on tile}
isPlayersPieceSelected{Is player's piece already selected}

beep[Beeping sound for invalid action]

selectPiece[Highlight selected piece]
highlightMoves[Highlight possible moves]


canMoveToTile{Can move to tile?}
hasTileOpponent{Has tile oppont}
exitToBattle((Exit to battle))
moveToTile[Move to tile]

START --> clickTile
clickTile --> isPlayersPieceOnTile
isPlayersPieceOnTile -- NO --> isPlayersPieceSelected
  isPlayersPieceSelected -- NO --> beep
  beep --> clickTile
  isPlayersPieceSelected -- YES --> canMoveToTile
    canMoveToTile -- NO --> beep
    canMoveToTile -- YES --> moveToTile
    moveToTile --> hasTileOpponent
      hasTileOpponent -- YES --> exitToBattle
      hasTileOpponent -- NO --> END
isPlayersPieceOnTile -- YES --> selectPiece
  selectPiece --> highlightMoves 
  highlightMoves --> clickTile
```

### Class Diagrams ###