var eraseOverlapIntervals = function(intervals) {
    if (intervals.length === 0) return 0;

    // ordena os intervalos pelo final (end)
    intervals.sort((a, b) => a[1] - b[1]);

    let count = 0; // numero de intervalos a remover
    let prevEnd = intervals[0][1];

    for (let i = 1; i < intervals.length; i++) {
        const [start, end] = intervals[i];

        if (start < prevEnd) {
            // sobreposição -> remover este intervalo
            count++;
        } else {
            // sem sobreposição -> atualiza o fim
            prevEnd = end;
        }
    }

    return count;
}
