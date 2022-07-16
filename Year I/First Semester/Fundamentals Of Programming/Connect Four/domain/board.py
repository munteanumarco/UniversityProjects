class Board:
    def __init__(self,rows,columns):
        self._columns = columns
        self._rows = rows
        self._data = [[0 for i in range(columns)] for j in range(rows)]
        self._human_turn = True
        self._directions = []
        self._last_move = [0,0]

    @property
    def columns(self):
        return self._columns

    @property
    def rows(self):
        return self._rows

    @property
    def human_turn(self):
        return self._human_turn

    @human_turn.setter
    def human_turn(self,value):
        self._human_turn = value

    @property
    def directions(self):
        return self._directions

    @directions.setter
    def directions(self,directions_array):
        self._directions = directions_array

    @property
    def last_move(self):
        return self._last_move

    @last_move.setter
    def last_move(self, tuple):
        self._last_move = tuple

    @property
    def data(self):
        return self._data


    def set_data(self,row,column,value):
        self._data[row][column] = value

    def __str__(self):
        string = ''
        for i in range(self._rows):
            for j in range(self._columns):
                string  = string + ' ' + str(self._data[i][j])
            string = string + '\n'
        return string




