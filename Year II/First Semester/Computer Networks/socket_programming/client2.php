<?php 
$HOST = "192.168.19.191"
$PORT = 8888;
$socket = socket_create(AF_INET,SOCK_STREAM,0);
socket_connect($s,$HOST,$PORT);
while(true) {
	$n = (int)readline('Enter the lenght:');
	for($i=0;$i<n;$i++) {
		$c = readline('char: ');
		socket_sendto($s,$c,1,0,$HOST,$PORT );
	}
	socket_recv($s,$result,$n,0);
	echo $result;
}
socket_close($s);
?>
