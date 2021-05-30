let startProgram =  function () {
	let a, b, c, d, e, f;

	function readCoefficient(coefficientName) {
		do {
			num = prompt(`Введите коэффицент ${coefficientName}`, 0);
		} while ( !isFinite(num) );

		if ( num === null || num === '') return null;

		return +num;
	}

	a = readCoefficient('a');
	b = readCoefficient('b');
	c = readCoefficient('c');
	d = readCoefficient('d');
	e = readCoefficient('e');
	f = readCoefficient('f');

	main(a, b, c, d, e, f);
}




function main(a, b, c, d, e, f) {
	let result = '';
	if ((a == 0) && (b == 0) && (c == 0) && (d == 0) && (e == 0) && (f == 0)) {
		result = '5';
	} else if ((a * d - c * b != 0) && ((e * d - b * f != 0) || (a * f - c * e != 0))) {
		let y = (a * f - c * e) / (a * d - c * b);
		let x = (d * e - b * f) / (d * a - b * c);
		result = `2 ${x} ${y}`;
	} else if (((a*d - c * b == 0) && ((e*d - b * f != 0) || (a*f - c * e != 0))) || 
		(a == 0 && c == 0 && e / b != f / d) || 
		(b == 0 && d == 0 && e / a != f / c) || 
		(a == 0 && b == 0 && c == 0 && d == 0 && (e / f > 0))) {

		if (((a == 0 && b == 0 && e == 0 && d != 0 && c == 0) || 
			(c == 0 && d == 0 && f == 0 && b != 0 && a == 0))) {
			let y;
			if (b == 0) {
				y = f / d;
			} else if  (d == 0) {
				y = e / b;
			} else if (e == 0 || f == 0) {
				y = 0;
			}
			result = `4 ${y}`;
			
		} else if (((a == 0 && b == 0 && e == 0 && c != 0 && d == 0) || 
			(c == 0 && d == 0 && f == 0 && a != 0 && b == 0))) {
			let x;
			if (a == 0) {
				x = f / c;
			} else if (c == 0) {
				x = e / a;
			} else if (e == 0 || f == 0) {
				x = 0;
			}
			result = `3 ${x}`;
		} else {
			result = `0`;
		}
	} else if (a == 0 && c == 0) {
		let y;
		if (e == 0) {
			y = f / d;
		} else if (f == 0) {
			y = e / b;
		} else {
			y = e / b;
		}
		result = `4 ${y}`;
	} else if (b == 0 && d == 0) {
		let x;
		if (e == 0) {
			x = f / c;
		} else if (f == 0) {
			x = e / a;
		} else {
			x = e / a;
		}
		result = `3 ${x}`;
	} else if (b == 0 && e == 0) {
		let k, n;
		k = -c / d;
		n = f / d;
		result = `1 ${k} ${n}`;
	} else if (d == 0 && f == 0) {
		let k, n;
		k = -a / b;
		n = e / b;
		result = `1 ${k} ${n}`;
	} else if (a == 0 && e == 0) {
		let k, n;
		k = -d / c;
		n = f / c;
		result = `1 ${k} ${n}`;
	} else if (c == 0 && f == 0) {
		let k, n;
		k = -b / a;
		n = e / a;
		result = `1 ${k} ${n}`;
	} else if ((a / b == c / d)) {
		let k, n;
		k = -c / d;
		n = f / d;
		result = `1 ${k} ${n}`; 
	} else {
		result = "Are you kidding me?";
	}
	return result;
}
