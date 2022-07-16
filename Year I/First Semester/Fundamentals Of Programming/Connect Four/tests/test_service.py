import unittest
from src.domain.board import Board
from src.service.board_service import BoardService
from src.domain.validators import BoardValidator,ConnectFourException

class TestService(unittest.TestCase):
    def setup(self):
        board = Board(6,7)
        board_service = BoardService(board,BoardValidator)
        return board,board_service

    def test__add_disc_to_board__ValidPosition__Added(self):
        board,board_service = self.setup()
        board_service.add_disc_to_board(5,6)
        data = board.data
        self.assertEqual(data[5][6],1)

    def test__add_disc_to_board__OutOfBoundsPosition__ExceptionThrown(self):
        board,board_service = self.setup()
        try:
            board_service.add_disc_to_board(10,10)
            assert False
        except ConnectFourException:
            assert True

    def test__add_disc_to_board__AlreadyOccupiedPosition__ExceptionThrown(self):
        board,board_service = self.setup()
        board.set_data(5,6,1)
        try:
            board_service.add_disc_to_board(5,6)
            assert False
        except ConnectFourException:
            assert True

    def test__add_disc_to_board__NoDiscBellowPosition__ExceptionThrown(self):
        board, board_service = self.setup()
        try:
            board_service.add_disc_to_board(4, 4)
            assert False
        except ConnectFourException:
            assert True

    def test__computer_move__NoDirections__ComputerMovedRandomly(self):
        board,board_service = self.setup()
        status = board_service.computer_move(5,6)
        self.assertEqual(status,0)
