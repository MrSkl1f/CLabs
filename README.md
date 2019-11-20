## Here you can find labs on C course.
### Now you can find here only 3 labs.
- Lab 8 is on dynamic arrays.
- Lab 9 is on dynamic matrixes.
- Lab 10 is on dynamic matrixes of structures.

### Lab 8 main task.
> Принять с клавиатуры положительное целое𝑛и последовательность𝑛действительныхчисел, которые следует записать в динамический массив 𝐴. Вычислить в соответствии с вариантом число 𝜇1 = 𝜇1(𝐴).Получить массив 𝐴1, удалив в соответствии с вариантом из динамического массива 𝐴 набор элементов по признаку. Обратите внимание: даже если на этом шаге несколько разиспользуется уже вычисленное 𝜇1, то оно не вычисляется заново. Если массив 𝐴1 сформировать невозможно, или он формируется пустым, считать ситуацию исключительной. Вычислить в соответствии с вариантом число 𝜇2 = 𝜇2(𝐴1).Получив с клавиатуры номер позиции 𝑝, сформировать массив 𝐴2, вставив с сохранением порядка сначала на позицию 𝑝 массива 𝐴1, а затем добавив в начало и в конецчисло 𝜇2. Обратите внимание: даже если на этом шаге используется несколько раз ужевычисленное 𝜇2, то оно не вычисляется заново. Если на момент вставки на позицию 𝑝 вмассиве меньше, чем 𝑝 + 1 элементов, считать ситуацию исключительной. Распечатать на экран массив 𝐴2.
> #### My variant.
> - Найти среднее геометрическое модулей.
> - Удалить из массива 𝐴 два элемента, имеющих минимальную разницу с заранее вычисленным числом 𝜇1 = 𝜇1(𝐴).
> - 𝜇2(𝑥) = (max(𝑥) min(𝑥)) / (1 +|max(𝑥)|+|min(𝑥)|).

### Lab 9 main task.
> Принять с клавиатуры 𝑚∈N, 𝑛∈N, 𝐴∈𝑀[𝑚×𝑛](Z), 𝑝∈N, 𝑞∈N, 𝐵∈𝑀[𝑝×𝑞](Z). Удаляя строки или столбцы, в соответствии с вариантом привести матрицы 𝐴 и 𝐵 к квадратному виду 𝐴1 и 𝐵1: 𝐴1∈𝑀[𝑘×𝑘](Z), where 𝑘 = min(𝑚, 𝑛), 𝐵1∈𝑀[𝑠×𝑠](Z), where 𝑠 = min(𝑝, 𝑞).Обратите внимание: если у матрицы больше строк, чем столбцов, то удалять нужно только строки, иначе — только столбцы. Добавляя в конец сначала строки, а потом столбцы, в соответствии с вариантом привести матрицы 𝐴1 и 𝐵1к одному размеру 𝐴2 и 𝐵2: 𝐴2, 𝐵2 ∈ 𝑀[𝑧×𝑧](Z),where𝑧= max(𝑘, 𝑠).Приняв с клавиатуры целые неотрицательные 𝜌 и 𝛾, вычислить и вывести на экран результат выражения A2^𝜌 * B2^𝛾.
> #### My variant.
> ##### Removal options.
> Удалять строки или столбцы с минимальным элементом в матрице. Если обнаружено несколько, считать целевым минимум, который был бы встречен первым при обходе по строкам.
> ##### Addition Options.
> Добавлять всегда сначала новые строки, потом — столбцы. Добавлять в новые строки округлённые к нижнему целому средние геометрические модулей элементов столбцов. Добавлять в новые столбцы максимумы по строкам.
