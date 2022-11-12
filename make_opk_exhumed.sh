#! /bin/sh

if [ -z "${TARGET}" ] ; then
    CURRENT_TARGET=gcw0
else
    CURRENT_TARGET=${TARGET}
fi

OPK_NAME=pcexhumed-${CURRENT_TARGET}.opk

DESKTOP_FILE=default.${CURRENT_TARGET}.desktop

echo ${OPK_NAME}

# create default.gcw0.desktop
cat > ${DESKTOP_FILE} <<EOF
[Desktop Entry]
Name=PCExhumed
Comment=Exhumed/Powerslave port
Exec=pcexhumed
Terminal=false
Type=Application
StartupNotify=true
Icon=pcexhumed
Categories=games;
X-OD-Manual=readme.pcexhumed.txt
EOF

# create opk
FLIST="${DESKTOP_FILE}"
FLIST="${FLIST} ./od-assets/pcexhumed.png"
FLIST="${FLIST} ./od-assets/readme.pcexhumed.txt"
FLIST="${FLIST} pcexhumed"
FLIST="${FLIST} pcexhumed.pk3"

rm -f ${OPK_NAME}
mksquashfs ${FLIST} ${OPK_NAME} -all-root -no-xattrs -noappend -no-exports

cat ${DESKTOP_FILE}
rm -f ${DESKTOP_FILE}
