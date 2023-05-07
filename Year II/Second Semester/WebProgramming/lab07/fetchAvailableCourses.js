$(document).ready(function() {
    console.log("start fetching data");
    $.ajax({
        url: 'getCourses.php',
        type: 'GET',
        dataType: 'json',
        success: function(data) {
            console.log(JSON.stringify(data));
            var select = $('#courses');
            $.each(data, function(index, row) {
                var newOption = $('<option>');
                newOption.attr('value', row.courseId);
                newOption.text(row.courseName);
                select.append(newOption);
            });
        }
    });
});