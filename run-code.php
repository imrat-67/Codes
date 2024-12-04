<?php
if ($_SERVER['REQUEST_METHOD'] === 'POST') {
    // Retrieve the submitted data
    $language = $_POST['language'];
    $code = $_POST['code'];
    $input = $_POST['input'];

    // Define temporary file paths
    $tempDir = sys_get_temp_dir();
    $codeFile = tempnam($tempDir, 'code');
    $inputFile = tempnam($tempDir, 'input');
    $outputFile = tempnam($tempDir, 'output');
    $errorFile = tempnam($tempDir, 'error');

    // Add appropriate extensions based on the language
    switch ($language) {
        case 'c': $codeFile .= '.c'; break;
        case 'cpp': $codeFile .= '.cpp'; break;
        case 'python': $codeFile .= '.py'; break;
        case 'java': $codeFile = $tempDir . '/Main.java'; break; // Java file must be named Main.java
        default:
            echo json_encode(["error" => "Unsupported language"]);
            exit;
    }

    // Write the code and input to files
    file_put_contents($codeFile, $code);
    file_put_contents($inputFile, $input);

    // Prepare the command to execute
    $command = '';
    switch ($language) {
        case 'c':
            $command = "gcc $codeFile -o $codeFile.out 2> $errorFile && $codeFile.out < $inputFile > $outputFile";
            break;
        case 'cpp':
            $command = "g++ $codeFile -o $codeFile.out 2> $errorFile && $codeFile.out < $inputFile > $outputFile";
            break;
        case 'python':
            $command = "python3 $codeFile < $inputFile > $outputFile 2> $errorFile";
            break;
        case 'java':
            $command = "javac $codeFile 2> $errorFile && java -cp $tempDir Main < $inputFile > $outputFile";
            break;
    }

    // Execute the command
    exec($command, $output, $returnCode);

    // Return output or errors
    if ($returnCode !== 0) {
        $error = file_get_contents($errorFile);
        echo json_encode(["error" => $error]);
    } else {
        $output = file_get_contents($outputFile);
        echo json_encode(["output" => $output]);
    }

    // Cleanup temporary files
    unlink($codeFile);
    unlink($inputFile);
    unlink($outputFile);
    unlink($errorFile);
    if (file_exists("$codeFile.out")) {
        unlink("$codeFile.out");
    }
}
?>
