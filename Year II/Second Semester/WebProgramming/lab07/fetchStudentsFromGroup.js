var group;
var course;
var courseId;
var pageSize = 4;
var currentPage = 1;
var totalRecords = 0;
var totalPages = 0;
var data;
$(document).ready(function() {
    console.log("start fetching datssa");
    var urlParams = new URLSearchParams(window.location.search);
    group = urlParams.get('group');
    course = urlParams.get('course');
    courseId = urlParams.get('courseId');
    $.ajax({
        url: 'getStudentsFromGroup.php?group=' + group + '&course=' + course + '&courseId=' + courseId,
        type: 'GET',
        dataType: 'json',
        success: function(response) {
           processData(response);
        }
    });
});

function processData(response) {
    totalRecords = response.length;
    totalPages = Math.ceil(totalRecords / pageSize);
    data = response
    updateTable();
}

function updateTable() {
    var tableBody = $('#data-table tbody');
    tableBody.empty();
    var startIndex = (currentPage - 1) * pageSize;
    var endIndex = Math.min(startIndex + pageSize, totalRecords);
    for (var i = startIndex; i < endIndex; i++) {
        var row = data[i];
        var newRow = $('<tr>');
        newRow.append($('<td>').text(row.firstName));
        newRow.append($('<td>').text(row.lastName));
        var groupButton, groupLink;
        if (row.grade === null) {
            row.grade = "No grade yet";
            groupButton = $('<button>').addClass('btn btn-primary').text('Add Grade');
            groupLink = $('<a>').attr('href', 'gradeStudent.php?studentId=' + row.studentId + '&courseId=' + courseId + '&course=' + course + "&grade=none" + "&sFirstName=" + row.firstName + "&sLastName=" + row.lastName).append(groupButton);
        
        }
        else {
            groupButton = $('<button>').addClass('btn btn-primary').text('Modify Grade');
            groupLink = $('<a>').attr('href', 'gradeStudent.php?studentId=' + row.studentId + '&courseId=' + courseId + '&course=' + course + '&grade=' + row.grade + "&sFirstName=" + row.firstName + "&sLastName=" + row.lastName).append(groupButton);
        
        }
        newRow.append($('<td>').text(row.grade));
        newRow.append($('<td>').append(groupLink));
        tableBody.append(newRow);
        }
    $('#page-info').text(`Page ${currentPage} of ${totalPages}`);
    $('#prev-btn').prop('disabled', currentPage === 1);
    $('#next-btn').prop('disabled', currentPage === totalPages);
}

function prev() {
    console.log("should go prev: ");
    currentPage--;
    updateTable();
};

function next() {
    console.log("should go next: ");
    currentPage++;
    updateTable();
};
