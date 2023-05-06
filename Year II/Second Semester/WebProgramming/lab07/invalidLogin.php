<html>
<head>

<script type="text/javascript">
	function redirect() {
		window.location.href = 'login.php';
}
</script>

<style>
	body {
		text-align: center;
		padding-top: 100px;
	}
</style>

</head>
<body onLoad="setTimeout('redirect()', 5000)">
	Authentication failed.<br/>
	You will be redirected to the login page in 5 seconds. Click <a href="login.php">here</a> to get to the login page yourself.
</body>
</html>
