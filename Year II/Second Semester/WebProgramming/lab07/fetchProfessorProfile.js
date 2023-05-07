$(document).ready(function() {
    console.log("start fetching data");
    $.ajax({
        url: 'profileProfessorRequest.php',
        type: 'GET',
        dataType: 'json',
        success: function(data) {
            console.log(JSON.stringify(data));
            var tableBody = $('#data-table tbody');
            var newRow = $('<tr>');
            newRow.append($('<td>').text(data.firstName));
            newRow.append($('<td>').text(data.lastName));
            newRow.append($('<td>').text(data.department));
            tableBody.append(newRow);
        },
        error: function(xhr, status, error) {
            console.log("Error: " + error); // Log the error to the console
            var errorMessage = $('<p>').text("Error: " + error);
            $('#data-table').after(errorMessage);
        }

    });
});