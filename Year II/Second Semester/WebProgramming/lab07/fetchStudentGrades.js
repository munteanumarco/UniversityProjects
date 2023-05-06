$(document).ready(function() {
    console.log("start fetching data");
    $.ajax({
        url: 'studentPanelRequest.php',
        type: 'GET',
        dataType: 'json',
        success: function(data) {
            console.log(JSON.stringify(data));
            var tableBody = $('#data-table tbody');
            $.each(data, function(index, row) {
                var newRow = $('<tr>');
                newRow.append($('<td>').text(row.name));
                newRow.append($('<td>').text(row.credits));
                if (row.grade === null) {
                    row.grade = "No grade yet";
                }
                newRow.append($('<td>').text(row.grade));
                tableBody.append(newRow);
            });
        },
        error: function(xhr, status, error) {
            console.log("Error: " + error); // Log the error to the console
            var errorMessage = $('<p>').text("Error: " + error);
            $('#data-table').after(errorMessage);
        }

    });
});