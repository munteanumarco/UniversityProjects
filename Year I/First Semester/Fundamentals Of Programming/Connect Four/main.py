from src.domain.board import Board
from src.service.board_service import BoardService
from src.domain.validators import BoardValidator
from src.ui.console import Console

if __name__ == '__main__':
    board = Board(6,7)
    board_service = BoardService(board,BoardValidator)
    console = Console(board_service)
    console.start_application()
