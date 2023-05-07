$(document).ready(function() {
    fetchGroups();
});


function fetchGroups() {
    console.log("start fetching data");
    $.ajax({
        url: 'getProfessorGroups.php',
        type: 'GET',
        dataType: 'json',
        success: function(data) {
            console.log(JSON.stringify(data));
            var tableBody = $('#data-table tbody');
            tableBody.empty();
            $.each(data, function(index, row) {
                var newRow = $('<tr>');
                newRow.append($('<td>').text(row.group));
                newRow.append($('<td>').text(row.courseName));
                var groupButton = $('<button>').addClass('btn btn-primary').text('See Group');
                var groupLink = $('<a>').attr('href', 'groupPage.php?group=' + row.group + "&course=" + row.courseName + "&courseId=" + row.courseId).append(groupButton);
                newRow.append($('<td>').append(groupLink));
                var removeButton = $('<button>').addClass('btn btn-danger').text('X').attr('onclick', 'removeGroupFromProfessor(' + row.courseId + ', "' + row.group + '")');
                newRow.append($('<td>').append(removeButton));
                tableBody.append(newRow);
            });
        },
        error: function(xhr, status, error) {
            console.log("Error: " + error); // Log the error to the console
            var errorMessage = $('<p>').text("Error: " + error);
            $('#data-table').after(errorMessage);
        }

    });
}


function removeGroupFromProfessor(courseId, group) {
    console.log(`should delete  course ${courseId}, group ${group}`);
    $.ajax({
        url: 'removeProfGroup.php',
        type: 'POST',
        dataType: 'json',
        data: {courseId: courseId, group: group},
        success: function() {
            console.log("delete done");
            fetchGroups();
        }
    });
}