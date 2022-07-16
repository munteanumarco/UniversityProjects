import unittest
from src.domain.board import Board
from src.domain.validators import BoardValidator,ConnectFourException


class TestBoard(unittest.TestCase):
    def test__rows_property__ValidValues__GetRows(self):
        board = Board(10,10)
        self.assertEqual(board.rows,10)

    def test__columns_property__ValidValues__GetColumns(self):
        board = Board(10, 10)
        self.assertEqual(board.columns, 10)

    def test___human_turn_property__ValidValues__GetHumanTurn(self):
        board = Board(10, 10)
        self.assertEqual(board.human_turn, True)

    def test__last_move_property__ValidValues__GotLastMove(self):
        board = Board(10,10)
        self.assertEqual(board.last_move,[0,0])

    def test__directions_property__ValidValues__GotDirections(self):
        board = Board(10,10)
        self.assertEqual(board.directions,[])

    def test__data_property__ValidValues__GotData(self):
        board = Board(2,2)
        self.assertEqual(board.data,[[0,0],[0,0]])

    def test__directions_setter__ValidValues__SetDirections(self):
        board = Board(3,3)
        board.directions = [[1,2],[3,4]]
        self.assertEqual(board.directions,[[1,2],[3,4]])

    def test__last_move_setter__ValidValues__SetLastMove(self):
        board = Board(4,4)
        board.last_move = [1,1]
        self.assertEqual(board.last_move,[1,1])

    def test__set_data__ValidValues__SetData(self):
        board = Board(5,5)
        board.set_data(1,2,3)
        data = board.data
        self.assertEqual(data[1][2],3)

    def test__human_turn_setter__ValidValues__SetHumanTurn(self):
        board = Board(10, 10)
        board.human_turn = False
        self.assertEqual(board.human_turn, False)

class TestValidator(unittest.TestCase):
    def test__validate_positions__ValidPositions__Validated(self):
        board = Board(5,5)
        BoardValidator.validate_positions(board,4,4)

    def test__validate_positions__OutOfBoundsPositions__ExceptionThrown(self):
        board = Board(5,5)
        try:
            BoardValidator.validate_positions(board,10,15)
            assert False
        except ConnectFourException:
            assert True

    def test__validate_positions__OccupiedPositions__ExceptionThrown(self):
        board = Board(6,6)
        board.set_data(5,4,1)
        try:
            BoardValidator.validate_positions(board,5,4)
            assert False
        except ConnectFourException:
            assert True

    def test__validate_positions__NoDiscBelow__ExceptionThrown(self):
        board = Board(5,6)
        try:
            BoardValidator.validate_positions(board,1,2)
            assert False
        except ConnectFourException:
            assert True
