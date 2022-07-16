class ConnectFourException(Exception):
    pass

class BoardValidatorException(ConnectFourException):
    pass

class BoardValidator:
    @staticmethod
    def validate_positions(board,row,column):
        board_data = board.data

        if row < 0 or column < 0 or board.rows-1 < row or board.columns-1 < column:
            raise BoardValidatorException("Invalid Position (out of bounds)\n")
        if row+1 < board.rows:
            if board_data[row][column] != 0 or board_data[row+1][column] == 0:
                raise BoardValidatorException("Invalid Position\n")
        if row + 1 == board.rows:
            if board_data[row][column] != 0:
                raise BoardValidatorException("Invalid Position\n")

    @staticmethod
    def check_vertical_line(board,last_disc_row,last_disc_column,turn):
        board_data = board.data

        # vertical line
        current_length = 0
        check_row = last_disc_row
        while check_row < board.rows:
            if board_data[check_row][last_disc_column] == turn:
                check_row += 1
                current_length += 1
                if current_length == 4:
                    return 1,current_length
            else:
                break
        return 0,current_length

    @staticmethod
    def check_horizontal_line(board,last_disc_row,last_disc_column,turn):
        board_data = board.data

        current_length = 0
        check_column = last_disc_column

        index_first_element_in_sequence = check_column-1
        index_last_element_in_sequence = check_column+1
        while check_column >= 0:
            if board_data[last_disc_row][check_column] == turn:
                current_length += 1
                check_column -= 1
                index_first_element_in_sequence = check_column
                if current_length == 4:
                    return 1,current_length,index_first_element_in_sequence,index_last_element_in_sequence
            else:
                break
        check_column = last_disc_column + 1
        while check_column < board.columns:
            if board_data[last_disc_row][check_column] == turn:
                current_length += 1
                check_column += 1
                index_last_element_in_sequence = check_column
                if current_length == 4:
                    return 1,current_length,index_first_element_in_sequence,index_last_element_in_sequence
            else:
                break

        return 0, current_length,index_first_element_in_sequence,index_last_element_in_sequence

    @staticmethod
    def check_first_diagonal(board,last_disc_row,last_disc_column,turn):
        board_data = board.data

        current_length = 0
        check_column = last_disc_column
        check_row = last_disc_row

        index_row_first_disc = last_disc_row-1
        index_column_first_disc = last_disc_column-1

        index_row_last_disc = last_disc_row+1
        index_column_last_disc = last_disc_column+1

        try:
            while check_column < board.columns and check_row < board.columns:
                if board_data[check_row][check_column] == turn:
                    current_length += 1
                    check_column += 1
                    check_row += 1
                    index_row_last_disc = check_row
                    index_column_last_disc = check_column
                    if current_length == 4:
                        return 1,0,0,0,0
                else:
                    break
        except Exception as exception:
            pass
        check_column = last_disc_column-1
        check_row = last_disc_row-1
        try:
            while check_column >= 0 and check_row >= 0:
                if board_data[check_row][check_column] == turn:
                    current_length += 1
                    check_column -= 1
                    check_row -= 1
                    index_column_first_disc = check_column
                    index_row_first_disc = check_row
                    if current_length == 4:
                        return 1,0,0,0,0,0
                else:
                    break
        except Exception as exception:
            pass
        return 0,current_length,index_row_first_disc,index_column_first_disc,index_row_last_disc,index_column_last_disc

    @staticmethod
    def check_second_diagonal(board,last_disc_row,last_disc_column,turn):
        board_data = board.data

        current_length = 0
        check_column = last_disc_column
        check_row = last_disc_row

        index_row_first_disc = last_disc_row - 1
        index_column_first_disc = last_disc_column + 1

        index_row_last_disc = last_disc_row + 1
        index_column_last_disc = last_disc_column - 1
        try:
            while check_column < board.columns and check_row >= 0:
                if board_data[check_row][check_column] == turn:
                    current_length += 1
                    check_column += 1
                    check_row -= 1
                    index_column_first_disc = check_column
                    index_row_first_disc = check_row
                    if current_length == 4:
                        return 1,4,0,0,0,0
                else:
                    break
        except:
            pass
        check_column = last_disc_column-1
        check_row = last_disc_row+1

        try:
            while check_column >= 0 and check_row < board.rows:
                if board_data[check_row][check_column] == turn:
                    current_length += 1
                    check_column -= 1
                    check_row += 1
                    index_column_last_disc = check_column
                    index_row_last_disc = check_row
                    if current_length == 4:
                        return 1,4,0,0,0,0
                else:
                    break
        except:
            pass
        return 0,current_length,index_row_first_disc,index_column_first_disc,index_row_last_disc,index_column_last_disc

    @staticmethod
    def check_draw(board):
        board_data = board.data
        for i in range(board.rows):
            for j in range(board.columns):
                if board_data[i][j] == 0:
                    return 0
        return -1

    @staticmethod
    def check_game_over(board,last_disc_row,last_disc_column,turn):
        max_disc_sequence = -1
        directions = []
        current_disc_sequence = 0

        status = BoardValidator.check_draw(board)
        if status != 0:
            return status,[]

        status,current_disc_sequence = BoardValidator.check_vertical_line(board,last_disc_row,last_disc_column,turn)
        if status != 0:
            return status,[]
        if max_disc_sequence < current_disc_sequence:
            max_disc_sequence = current_disc_sequence
            directions.append([last_disc_row-1,last_disc_column])

        status,current_disc_sequence,index_first_disc,index_last_disc = BoardValidator.check_horizontal_line(board,last_disc_row,last_disc_column,turn)
        if status != 0:
            return status,[]
        if max_disc_sequence < current_disc_sequence:
            max_disc_sequence = current_disc_sequence
            directions.append([last_disc_row,index_first_disc])
            directions.append([last_disc_row, index_last_disc])

        status,current_disc_sequence,index_row_first_disc,index_column_first_disc,index_row_last_disc,index_column_last_disc = BoardValidator.check_first_diagonal(board, last_disc_row, last_disc_column, turn)
        if status != 0:
            return status,[]
        if max_disc_sequence < current_disc_sequence:
            directions = []
            max_disc_sequence = current_disc_sequence
            directions.append([index_row_first_disc,index_column_first_disc])
            directions.append([index_row_last_disc, index_column_last_disc])

        status,current_disc_sequence,index_row_first_disc,index_column_first_disc,index_row_last_disc,index_column_last_disc = BoardValidator.check_second_diagonal(board, last_disc_row, last_disc_column, turn)
        if status != 0:
            return status,[]
        if max_disc_sequence < current_disc_sequence:
            directions = []
            max_disc_sequence = current_disc_sequence
            directions.append([index_row_first_disc,index_column_first_disc])
            directions.append([index_row_last_disc, index_column_last_disc])

        return 0,directions
