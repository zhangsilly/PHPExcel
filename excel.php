<?php
error_reporting(E_ALL);
$ts	= gettimeofday(true);
$excel	= Excel::create(1, 'GBK');
echo $excel->getCharset();
$font	= new ExcelFont(ExcelFont::WEIGHT_BOLD);
$font->setColor(ExcelFont::COLOR_RED);
$cellFmt	= new ExcelCellFormat($excel);
$cellFmt->setFont($font);
$sheet	= $excel->getWorkSheet(0);
for ($row = 0; $row < 6000; ++ $row)
{
	for ($col = 0; $col < 30; ++ $col)
	{
		$sheet->setWString($row, $col, '我是一只鱼', $cellFmt);
	}
}
$excel->saveAs('aaa.xls');
echo gettimeofday(true) - $ts, "\r\n";