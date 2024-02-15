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

clickTile[Player cliks 
          on a tile]
isPlayersPieceOnTile{Is player's piece 
                      on selected tile}
isPlayersPieceSelected{Is player's piece 
                        already selected}

beep[Beeping sound 
      for invalid action]

selectPiece[Highlight selected piece
            and its valid moves]


canMoveToTile{Can move to tile?}
hasTileOpponent{Tile has 
                opposing piece}
battle[Battle]
moveToTile[Move to tile]

START --> clickTile
clickTile --> isPlayersPieceOnTile
isPlayersPieceOnTile -- NO --> isPlayersPieceSelected
isPlayersPieceOnTile -- YES --> selectPiece
  selectPiece --> clickTile
  isPlayersPieceSelected -- YES --> canMoveToTile
    canMoveToTile -- YES --> moveToTile
      moveToTile --> hasTileOpponent
        hasTileOpponent -- YES --> battle
        hasTileOpponent -- NO --> END
    canMoveToTile -- NO --> beep
  isPlayersPieceSelected -- NO --> beep
    beep --> clickTile
  battle --> END
```

### Class Diagrams ###

```mermaid

classDiagram

class EventListener{
  -std::map<uint32, function> actions
  +regAction(uint32, function): void
  +delAction(uint32): void
  +executeAction(uint32, args...): void
}

class Component{
  <<Abstract>>
  +render(SDL_Renderer*): void
  #rect: SDL_Rect
}

class LabelComp{
  +render(SDL_Renderer*): void
  -text: string
  -fontName: string
  -fontSize: int
}

class PanelComp{
  +render(SDL_Renderer*):void
  +registerComponent(Component*):void
  +removeComponent(Component*):void
  -components: std::vector<Component*>
}

class Game{
  <<Abstract>>
  -logic: GameLogic
  +run(): int
}

class SDL_Game{
  -display: SDL_Display
  -window: SDL_Window
  -renderer: SDL_Renderer
  -listeners: EventListener*[]
  -components: Component*[]
  -handleEvents(): bool
  +init(): bool
  +run(): int
}

class GameLogic{
  -board: Tile[][]
  +getValidMoves(Coord, DeltaCoord[]): Coord[]
  +getPieceCoord(Piece): Coord
  +movePiece(Piece, DeltaCoord): void
}

class Tile{
  -piece: Piece
  -isLake: bool
}

class Piece{
  <<Abstract>>
  -movePattern: DeltaCoord[] //static
  -rank: int
  -board: Board
  +attack(Piece): void
  +getAvailableMoves(): Coord[]
}

class Bomb{ }
class Marshal{  }
class General{  }
class Colonel{  }
class Major{  }
class Captain{  }
class Lieutenant{ }
class Sergeant{ }
class Miner{  }
class Scout{  }
class Spy{  }
class Flag{ }

 
class DeltaCoord{
  -dx: int
  -dy: int
}

class Coord{
  -x: int
  -y: int
}

Game <|-- SDL_Game
Game *-- GameLogic
SDL_Game *-- EventListener
EventListener o-- GameLogic

Component <|-- PanelComp
Component <|-- LabelComp
SDL_Game *-- Component

GameLogic *-- Tile
Tile o-- Piece
DeltaCoord --o Piece

Piece <|-- Bomb
Piece <|-- Marshal
Piece <|-- General
Piece <|-- Colonel
Piece <|-- Major
Piece <|-- Captain
Piece <|-- Lieutenant
Piece <|-- Sergeant
Piece <|-- Miner
Piece <|-- Scout
Piece <|-- Spy
Piece <|-- Flag
```