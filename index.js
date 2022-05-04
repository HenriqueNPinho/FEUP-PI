var connect = require('connect');
var serveStatic = require('serve-static');

const port = 8000;
//(with path)

connect()
.use(serveStatic(__dirname))
.listen(port, () => console.log(`Server running at http://localhost:${port}/`));

  