#!/bin/bash

# Output the RCC file header
echo '<!DOCTYPE RCC>'
echo '<RCC version="1.0">'
echo '    <qresource prefix="/">'

find sprites -name '*.png' -print0 | xargs -0 -I{} echo "        <file>{}</file>"


# Output the RCC file footer
echo '    </qresource>'
echo '</RCC>'
