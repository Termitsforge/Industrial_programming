describe("Решения системы (a*x+b*y=e)&&(c*x+d*y=f)", function() {

	describe(`Любая пара чисел (x, y) является решением`, function() {
		it(`a = b = c = d = e = f = 0`, function() {
			assert.equal(main(0, 0, 0, 0, 0, 0), '5');
		});
	});
	
	describe(`Система не имеет решений`, function() {
		it(`a = b = c = d = 0`, function() {
			assert.equal(main(0, 0, 0, 0, 0, 5.5), '0');
			assert.equal(main(0, 0, 0, 0, 1/2, 3/2), '0');
			assert.equal(main(0, 0, 0, 0, 9, 5), '0');
		});
		it(`a*d = c*b`, function(){
			assert.equal(main(1, 2, 1, 2, 0, 2), '0');
			assert.equal(main(3, 1, 2, 2/3, 0, 8), '0');
		});
		it(`a = b = c = d отлично от 0`, function() {
			assert.equal(main(2, 2, 2, 2, 6, 8), '0');
			assert.equal(main(2.3, 2.3, 2.3, 2.3, 0, 8), '0');
			assert.equal(main(1/9, 1/9, 1/9, 1/9, 6/20, 8/40), '0');
		});
	});
	
	describe(`Система имеет единственное решение (x0, y0)`, function() {
		it(`Оба корня ненулевые`, function() {
			assert.equal(main(2, 2, 5, 6, 5, 4), '2 11 -8.5');
			assert.equal(main(1, 1, 2, 1, 2, 3), '2 1 1');
		});
		it(`x = 0`, function() {
			assert.equal(main(1, 2, 2, 1, -2, -1), '2 0 -1');
			assert.equal(main(10, 2, 12, 2, 4, 4), '2 0 2');
		});
		it(`y = 0`, function() {
			assert.equal(main(1, 2, 2, 1, -1, -2), '2 -1 0');
			assert.equal(main(1.1, 3, 1.1, 4, 1.1, 1.1), '2 1 0');
		});
	});
	
	describe(`Система имеет бесконечно много решений вида x=x0, y — любое`, function() {
		it(`a*x = e`, function() {
			assert.equal(main(1, 0, 0, 0, 2, 0), '3 2');
			assert.equal(main(1.5, 0, 0, 0, 3, 0), '3 2');
			assert.equal(main(1/2, 0, 0, 0, 2, 0), '3 4');
		});
		it(`c*x = f`, function() {
			assert.equal(main(0, 0, 1, 0, 0, 5), '3 5');
			assert.equal(main(0, 0, 3/2, 0, 0, 6), '3 4');
			assert.equal(main(0, 0, 0.5, 0, 0, 5.5), '3 11');
		});
		it(`a*x = e && c*x = f`, function() {
			assert.equal(main(2, 0, 1, 0, 6, 3), '3 3');
			assert.equal(main(2.0, 0, 3.0, 0, 4.0, 6.0), '3 2');
			assert.equal(main(5/3, 0, 5/3, 0, 5, 5), '3 3');
		});
	});
	
	describe(`Система имеет бесконечно много решений вида y=y0, x — любое`, function() {
		it(`b*y = e`, function() {
			assert.equal(main(0, 1, 0, 0, 3, 0), '4 3');
			assert.equal(main(0, 1/3, 0, 0, 3, 0), '4 9');
			assert.equal(main(0, 1.6, 0, 0, 2, 0), '4 1.25');
		});
		it(`d*y = f`, function() {
			assert.equal(main(0, 0, 0, 8, 0, 2), '4 0.25');
			assert.equal(main(0, 0, 0, 1/3, 0, 2), '4 6');
			assert.equal(main(0, 0, 0, 1.4, 0, 2.8), '4 2');
		});
		it(`b*y = e && d*y = f`, function(){
			assert.equal(main(0, 4, 0, 8, 1, 2), '4 0.25');
			assert.equal(main(0, 1, 0, 1/3, 6, 2), '4 6');
			assert.equal(main(0, 2.5, 0, 1.4, 5, 2.8), '4 2');
		});
	});
	
	describe(`Система имеет бесконечно много решений, каждое из которых имеет вид y=kx+n`, function() {
		it(`c = d = f = 0`, function() {
			assert.equal(main(1, 1, 0, 0, 2, 0 ), '1 -1 2');
			assert.equal(main(1, 4, 0, 0, 30, 0 ), '1 -0.25 7.5');
			assert.equal(main(-1/4, 1/2, 0, 0, 1/5, 0 ), '1 0.5 0.4');
		});
		it(`a = b = e = 0`, function() {
			assert.equal(main(0, 0, 1, 2, 0, 2 ), '1 -0.5 1');
			assert.equal(main(0, 0, 1/10, 1/5, 0, -1 ), '1 -0.5 -5');
		});
		it(`c = k*a, d = k*b, f = k*e `, function() {
			assert.equal(main(-4, 8, -4, 8, 2, 2), '1 0.5 0.25');
			assert.equal(main(1, 1, 3, 3, 8, 24), '1 -1 8');
		});
	});
	
	describe(`'Are you kidding me?' не числа`, function() {
		it(`все ' ' ожидается 'Are you kidding me?' js приводит пустую строчку к 0`, function() {
			assert.equal(main(' ', ' ', ' ', ' ', ' ', ' '), 'Are you kidding me?');
		});
		it(`все null `, function() {
			assert.equal(main(null, null, null, null, null, null), "Are you kidding me?");
		});
		it(` все undefined`, function() {
			assert.equal(main(undefined, undefined, undefined, undefined, undefined, undefined), "Are you kidding me?");
		});
		it(` все объекты`, function() {
			assert.equal(main({}, {}, {}, {}, {}, {}), "Are you kidding me?");
		});
	});
});