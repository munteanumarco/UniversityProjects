<?php
require 'vendor/autoload.php';
use Firebase\JWT\JWT;
function validate() {
    $headers = null;
    $token = null;
    if (isset($_SERVER['Authorization'])) {
        $headers = trim($_SERVER["Authorization"]);
    }
    else if (isset($_SERVER['HTTP_AUTHORIZATION'])) { //Nginx or fast CGI
        $headers = trim($_SERVER["HTTP_AUTHORIZATION"]);
    } elseif (function_exists('apache_request_headers')) {
        $requestHeaders = apache_request_headers();
        // Server-side fix for bug in old Android versions (a nice side-effect of this fix means we don't care about capitalization for Authorization)
        $requestHeaders = array_combine(array_map('ucwords', array_keys($requestHeaders)), array_values($requestHeaders));
        //print_r($requestHeaders);
        if (isset($requestHeaders['Authorization'])) {
            $headers = trim($requestHeaders['Authorization']);
        }
    }
    if (!empty($headers)) {
        if (preg_match('/Bearer\s(\S+)/', $headers, $matches)) {
            $token = $matches[1];
        }
    }

    $secretKey = "my-secret-key";
    $tokenParts = explode('.', $token);
    $payloadBase64 = $tokenParts[1];
    $payload = base64_decode($payloadBase64);
    $decodedPayload = json_decode($payload, true);


    if ($decodedPayload['role'] !== 'professor') {
        return false;
    }

    return true;
}