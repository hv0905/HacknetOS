if ($args.Count -gt 0) {
    $srcD = $args[0];
}

if ($null -eq $srcD -or( Get-Content $srcD -eq $null)) {
    # prompt user to input the path
    $srcD = Read-Host -Prompt "Enter the path of the source directory: ";
}

if ($null -eq (Get-ChildItem $srcD)) {
    Write-Error "The source directory does not exist.";
    exit 1;
}

Write-Host -ForegroundColor Green "Generating bgm directory...";

$backgroundMusic = Get-ChildItem $srcD -Filter "*Revole*.mp3";
$gotmail = Get-ChildItem $srcD -Filter "*You Got Mail*.mp3";

if ($null -eq (Get-ChildItem -Directory -Filter "bgm")) {
    New-Item -Path "bgm" -Type Directory;
}

if ($null -ne $backgroundMusic) {
    Write-Host -ForegroundColor Green "Copying Revole...";
    Copy-Item $backgroundMusic -Destination "bgm/0.mp3";
} else {
    Write-Host -ForegroundColor Yellow "Cannot find Revole";
}

if ($null -ne $gotmail) {
    Write-Host -ForegroundColor Green "Copying You Got Mail...";
    Copy-Item $gotmail -Destination "bgm/n0.mp3";
} else {
    Write-Host -ForegroundColor Yellow "Cannot find You Got Mail";
}

Write-Host -ForegroundColor Green "Operation completed."


