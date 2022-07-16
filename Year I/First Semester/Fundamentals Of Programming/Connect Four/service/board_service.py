import random
from src.domain.board import Board
from src.domain.validators import ConnectFourException

class BoardServiceException(ConnectFourException):
    pass

class BoardService:
    def __init__(self,board,board_validator):
        self._board = board
        self._board_validator = board_validator

    def get_valid_position(self,column):
        row = 0
        for index in range(self._board.rows):
            if self._board.data[index][column] == 0:
                row = index
            else:
                break
        return row

    def add_disc_to_board(self,row,column):
        if self._board.human_turn is True:
            row = self.get_valid_position(column)
            self._board.set_data(row,column,1)
            self._board.last_move = (row, column)
            status, directions = self._board_validator.check_game_over(self._board, row, column, 1)
            self._board.directions = directions
        else:
            self._board_validator.validate_positions(self._board,row,column)
            self._board.set_data(row,column,2)
            status, directions = self._board_validator.check_game_over(self._board, row, column, 2)

        return status

    def computer_move(self,last_disc_row,last_disc_column):
        directions = self._board.directions
        added = False
        for direction in directions[::-1]:
            try:
                 if direction[0] >= 0 and direction[1] >= 0:
                    status = self.add_disc_to_board(direction[0],direction[1])
                    added = True
                    break
            except :
                pass

        if added is False:
            while True:
                row = random.randint(0,5)
                column = random.randint(0,6)
                try:
                    status = self.add_disc_to_board(row,column)
                    break
                except:
                    pass
        return status
