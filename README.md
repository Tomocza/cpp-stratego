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
boardSetup --> isDraw
isDraw -- NO --> isPlayerWin
isDraw -- YES -----> END1
isPlayerWin -- NO --> playerActs
isPlayerWin -- YES ----> END0
playerActs --- playerSwitch
playerSwitch --> isDraw

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

START --> isOwnSide
isOwnSide -- YES --> isPosEmpty
isOwnSide -- NO --> EXIT0
isPosEmpty -- YES --> EXIT1
isPosEmpty -- NO --> EXIT0

```
### Class Diagrams ###