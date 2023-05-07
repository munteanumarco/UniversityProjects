$(document).ready(function() {
    console.log("start fetching data");
    $.ajax({
        url: 'getGroups.php',
        type: 'GET',
        dataType: 'json',
        success: function(data) {
            console.log(JSON.stringify(data));
            var select = $('#groups');
            $.each(data, function(index, row) {
                var newOption = $('<option>');
                newOption.attr('value', row.facultyGroup);
                newOption.text(row.facultyGroup);
                select.append(newOption);
            });
        }
    });
});