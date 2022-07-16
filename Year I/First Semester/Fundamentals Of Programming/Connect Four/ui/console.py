from src.domain.validators import ConnectFourException
class ConsoleException(ConnectFourException):
    pass

class Console:
    def __init__(self,board_service):
        self._board_service = board_service

    def print_board(self):
        print(str(self._board_service._board))

    def add_disc_to_board(self):
        print("==Position of new disc==\n")
        column = input("Please insert column index (from 1 to 7, 1 is the first column, 7 is the last column):")
        try:
            column = int(column)
        except:
            raise ConsoleException("Invalid column")
        return self._board_service.add_disc_to_board(-1,column-1)

    def start_application(self):
        user_input = input("Please press 1 to start the game:")
        try:
            user_input = int(user_input)
        except Exception as exception:
            print(exception)
        if user_input != 1:
            return
        status = 0
        while True:
            try:
                self.print_board()
                board = self._board_service._board

                if status == 1 and board.human_turn == True:
                    print("Game Over, Computer Won!")
                    break
                else:
                    if status == 1 and board.human_turn == False:
                        print("You Won!")
                        break
                    elif status == -1:
                        print("Draw!")
                        break

                if board.human_turn == True:
                    print("Human Turn")
                    status = self.add_disc_to_board()
                    board.human_turn = False
                else:
                    print("Computer Turn")
                    last_move = board.last_move
                    status = self._board_service.computer_move(last_move[0],last_move[1])
                    board.human_turn = True

            except ConnectFourException as exception:
                print(exception)